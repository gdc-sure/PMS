#pragma once



// CRoomView ��ͼ

class CRoomView : public CScrollView
{
	DECLARE_DYNCREATE(CRoomView)

protected:


public:
		CRoomView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CRoomView();
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��

	DECLARE_MESSAGE_MAP()
};


