#ifndef BOYRING_H_2020
#define  BOYRING_H_2020
/*JosephusԼɪ������
BoyRing������� 
*/
/*��� 
*/
class Boy{
public:
	int code;//��� 
	Boy* next;//��� 

};
/*
ѭ������ 
*/
class BoyRing{
private:
	Boy* head, * cur, * pre;//ͷ, ��ǰ, ��ǰ����ǰ�� 
public:
	//���캯��:��ʼ������
	BoyRing(int); 
	
	//����ѭ������,��� 
	void showAll();
	
	//��m���� ,ʹ��curָ���m����� 
	void countNum(int m); 
	
	//��ȡ��ǰ���ı��
	int getCodeCur(); 
	
	//ɾ��:����ǰ���ӻ���ɾ�� 
	void delNode(); 
	
	//��������
	~BoyRing(); 
	
}; 

#endif // BOYRING_H_2020
