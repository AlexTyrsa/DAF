#pragma once

#include "../circular_iterator/circular_iterator.h"

#include <QIODevice>
#include <array>

class QSampleProcessor : public QIODevice
{
    Q_OBJECT

public:
    Q_PROPERTY(int delaySamples READ delaySamples WRITE setDelaySamples NOTIFY delaySamplesChanged)
    Q_PROPERTY(int bytesPerSample READ bytesPerSample WRITE setBytesPerSample NOTIFY bytesPerSampleChanged)

public:
    QSampleProcessor(int inBytesPerSample, QObject* inParent = nullptr);

    qint64 bytesAvailable() const override;

    int delaySamples() const;
    int bytesPerSample() const;

public slots:
    void setDelaySamples(int inDelay);
    void setBytesPerSample(int inBytesPerSample);

signals:
    void delaySamplesChanged(int);
    void bytesPerSampleChanged(int);

protected:
    qint64 readData(char *inData, qint64 inMaxLen) override;
    qint64 writeData(const char *inData, qint64 inLen) override;

private:
    void remapBuffer();

private:
    static const int cChunkSize = 4096;
    static const int cChunkNum  = 1000;
    static const int cBuffSize = cChunkNum * cChunkSize;
    struct CChunkInfo;

    typedef std::array<char, cBuffSize>           CBuffer;
    typedef std::array<CChunkInfo, cChunkNum>     CBufferInfoI;
    typedef std::array<CChunkInfo, cChunkNum + 1> CBufferInfoO;

    struct CChunkInfo
    {
        CBuffer::iterator chunkBegin;
        CBuffer::iterator chunkEnd;
        int               sampleIdxInBuf = 0;
    };

private:
    CBuffer      mBuffer;
    CBufferInfoI mInputMap;
    CBufferInfoO mOutputMap;

    circular_iterator<CBufferInfoI::iterator> mInputMapIterator;
    circular_iterator<CBufferInfoO::iterator> mOutputMapIterator;

    int mDelaySamples;
    int mBytesPerSample;

};
