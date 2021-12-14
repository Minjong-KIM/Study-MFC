# 직렬화
저장 매체에 객체의 내용을 저장하거나 읽어오는 기법이다. CArchive 객체를 이용해 CFile::Read()나 CFile::Write() 함수 대신 << 또는 >> 연산자로 파일 입출력을 할 수 있다.
# CArchive::CArchive(CFile* pFile, UINT nMode, int nBufSize, void* lpBuf)
1. pFile -> 데이터를 저장하거나 읽을 파일 객체
2. nMode -> CArchive::store 또는 CArchive::load로, 저장할 것인지 또는 읽을 것인지 나타낸다.
3. nBufSize -> CArchive 클래스 내부에서 사용할 버퍼의 크기로 대부분 디폴트 인자를 사용한다.
4. lpBuf -> 버퍼를 위한 메모리로 주로 디폴트 인자를 사용한다.
# Serialize()
도큐먼트 클래스의 Serialize() 함수를 재정의 하여 어떤 데이터를 저장할 것인지 또는 어떤 데이터를 읽을 것인지 정해주어야 한다.