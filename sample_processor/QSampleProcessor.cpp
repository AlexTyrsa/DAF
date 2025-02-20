#include "QSampleProcessor.h"

QSampleProcessor::QSampleProcessor(int inBytesPerSample, QObject *inParent) : QIODevice(inParent), mDelaySamples(0), mBytesPerSample(inBytesPerSample), mPause(false)
{
    int outIdx = 0;

    for(CBuffer::iterator bufI = mBuffer.begin(); bufI != mBuffer.end(); bufI += cChunkSize, ++outIdx)
        mInputMap[outIdx] = {bufI, bufI + cChunkSize, (outIdx * cChunkSize) / mBytesPerSample};

    remapBuffer();
}

qint64 QSampleProcessor::bytesAvailable() const
{
    return mBuffer.size() + QIODevice::bytesAvailable();
}

int QSampleProcessor::delaySamples() const
{
    return mDelaySamples;
}

int QSampleProcessor::bytesPerSample() const
{
    return mBytesPerSample;
}

bool QSampleProcessor::pause() const
{
    return mPause;
}

void QSampleProcessor::setDelaySamples(int inDelay)
{
    if(inDelay != delaySamples())
    {
        mDelaySamples = inDelay;

        remapBuffer();

        emit delaySamplesChanged(delaySamples());
    }
}

void QSampleProcessor::setBytesPerSample(int inBytesPerSample)
{
    if(inBytesPerSample != bytesPerSample())
    {
        mBytesPerSample = inBytesPerSample;

        remapBuffer();

        emit bytesPerSampleChanged(bytesPerSample());
    }
}

void QSampleProcessor::setPause(bool inPause)
{
    if(inPause != pause())
    {
        mPause = inPause;

        mBuffer.fill(0);

        emit pauseChanged(pause());
    }
}

qint64 QSampleProcessor::readData(char *inData, qint64 inMaxLen)
{
    qint64 writeLen = 0;
    bool isQuit = false;

    const CChunkInfo& inputChunk = *mInputMapIterator;
    qint64 inputSamples = (mBuffer.size() / mBytesPerSample) * mInputMapIterator.circle() + inputChunk.sampleIdxInBuf;

    while(!isQuit)
    {
        const CChunkInfo& outputChunk = *mOutputMapIterator;
        qint64 chunkLen = outputChunk.chunkEnd - outputChunk.chunkBegin;
        qint64 outputSamples = (mBuffer.size() / mBytesPerSample) * mOutputMapIterator.circle() + outputChunk.sampleIdxInBuf;

        if(chunkLen >= 0 && writeLen + chunkLen <= inMaxLen && inputSamples - outputSamples >= delaySamples())
        {
            if(!pause())
                std::copy(outputChunk.chunkBegin, outputChunk.chunkEnd, inData + writeLen);

            writeLen += chunkLen;
            ++mOutputMapIterator;
        }else
            isQuit = true;
    }

    return writeLen;
}

qint64 QSampleProcessor::writeData(const char *inData, qint64 inLen)
{
    qint64 readLen = 0;
    bool isQuit = false;

    const CChunkInfo& outputChunk = *mOutputMapIterator;

    while(!isQuit)
    {
        const CChunkInfo& inputChunk = *mInputMapIterator;
        qint64 chunkLen = inputChunk.chunkEnd - inputChunk.chunkBegin;

        if(chunkLen > 0 && readLen + chunkLen <= inLen)
        {
            std::copy(inData, inData + chunkLen, inputChunk.chunkBegin);

            readLen += chunkLen;
            ++mInputMapIterator;
        }else
            isQuit = true;
    }

    return readLen;
}

void QSampleProcessor::remapBuffer()
{
    mBuffer.fill(0);

    int outIdx = 0;
    CBuffer::iterator bufI;

    for(bufI = mBuffer.begin() + mDelaySamples * mBytesPerSample; bufI < mBuffer.end(); bufI += cChunkSize, ++outIdx)
        mOutputMap[outIdx] = {bufI, bufI + cChunkSize, mDelaySamples + (outIdx * cChunkSize) / mBytesPerSample + 1};

    bufI -= cChunkSize;
    --outIdx;
    int halfChunkSize = mBuffer.end() - bufI;
    int sampleIdxInBuf = mDelaySamples + (outIdx * cChunkSize) / mBytesPerSample + 1;

    mOutputMap[outIdx++] = {bufI, mBuffer.end(), sampleIdxInBuf};
    sampleIdxInBuf += halfChunkSize / mBytesPerSample;
    mOutputMap[outIdx++] = {mBuffer.begin(), mBuffer.begin() + cChunkSize - halfChunkSize, sampleIdxInBuf};

    for(bufI = mBuffer.begin() + cChunkSize - halfChunkSize; bufI < mBuffer.begin() + mDelaySamples * mBytesPerSample; bufI += cChunkSize, ++outIdx)
        mOutputMap[outIdx] = {bufI, bufI + cChunkSize, (outIdx * cChunkSize) / mBytesPerSample + 1};

    mInputMapIterator  = circular_iterator<CBufferInfoI::iterator>(mInputMap.begin(), mInputMap.end());
    mOutputMapIterator = circular_iterator<CBufferInfoO::iterator>(mOutputMap.begin(), mOutputMap.end());
}
