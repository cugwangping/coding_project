
// MFC_CreatBinaryTreeDoc.h : CMFC_CreatBinaryTreeDoc ��Ľӿ�
//


#pragma once


class CMFC_CreatBinaryTreeDoc : public CDocument
{
protected: // �������л�����
	CMFC_CreatBinaryTreeDoc();
	DECLARE_DYNCREATE(CMFC_CreatBinaryTreeDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFC_CreatBinaryTreeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
