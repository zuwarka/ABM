#include <iostream>

//����������� ���
//����������� ����� ������ � ������� ������������ �����������
//5. � ������� �� 10 ����� �������� ��� ������������� �������� �� ������������ ������� �������

using namespace std;

int main()
{
	signed short int A[10], max; //������ � ������������ �������
	char inputting[] = "%hd", outputting[] = "%hd "; //������ ����� �������� � ������ ��������
	
	__asm
	{
		lea esi, A //������ � ������� ������� ��������� ����� ������� (������ �������)
		mov ecx, 10
		Inputting: 
		push esi
		push ecx
		push esi
		lea eax, inputting
		push eax
		call scanf
		add esp, 8
		pop ecx //����� ���-�� ��������� �������
		pop esi //����� ����� �������
		add esi, 2; //��������� �� ��������� �������, ���� �� ���������� 
		loop Inputting

		mov esi, 0 //�������� (������)
		mov cx, 10 //���������� ������� �������
		mov max, 0 //� ������������ ������ ����

		Findingmax:
		mov ax, 0
		mov ax, A[esi*2]
		cmp ax, max
		jl Foundmax //���� ���� ������ �������� �������, �� ���� �������� �� ������� �������
		mov max, ax //������ � ���� ������� ������� �������
		Foundmax:
		inc esi
		dec cx
		cmp cx, 0
		jne Findingmax //�������� ������� �����

		mov cx, 10
		mov bx, 0
		mov esi, 0
		mov ax, 0
		cmp ax, max
		je Exit //���� ���� = 0, �� ������ ������� ��� ���������

		Divcycle:
		mov ax, A[esi*2]
		cmp ax, 0
		jge Next //���� ������� ������ ����, �� �� ����� �������������, �����  - ������� �� �����
		mov dx, 0
		mov ax, A[esi*2]
		mov bx, max
		cwd
		idiv bx
		mov A[esi*2], ax
		Next:
		inc esi
		dec cx
		cmp cx, 0
		jne Divcycle

		Exit:
		mov ecx, 10
		lea esi, A
		Outputting:
		push esi
		push ecx
		push [esi]
		lea eax, outputting
		push eax
		call printf
		add esp, 8
		pop ecx
		pop esi
		add esi, 2
		loop Outputting
	}
	return 0;
}
