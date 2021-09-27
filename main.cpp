#include <iostream>

//Организация ЭВМ
//Организация ввода вывода с помощью ассемблерной архитектуры
//5. В массиве из 10 чисел поделить все отрицательные элементы на максимальный элемент массива

using namespace std;

int main()
{
	signed short int A[10], max; //массив и максимальный элемент
	char inputting[] = "%hd", outputting[] = "%hd "; //массив ввода символов и вывода символов
	
	__asm
	{
		lea esi, A //вносим в регистр индекса источника адрес массива (первый элемент)
		mov ecx, 10
		Inputting: 
		push esi
		push ecx
		push esi
		lea eax, inputting
		push eax
		call scanf
		add esp, 8
		pop ecx //берем кол-во элементов массива
		pop esi //берем адрес массива
		add esi, 2; //переходим на следующий элемент, пока не закончатся 
		loop Inputting

		mov esi, 0 //обнуляем (массив)
		mov cx, 10 //двубайтный счетчик массива
		mov max, 0 //в максимальном теперь ноль

		Findingmax:
		mov ax, 0
		mov ax, A[esi*2]
		cmp ax, max
		jl Foundmax //если макс меньше элемента массива, то макс меняется на элемент массива
		mov max, ax //теперь в макс больший элемент массива
		Foundmax:
		inc esi
		dec cx
		cmp cx, 0
		jne Findingmax //проверка условия цикла

		mov cx, 10
		mov bx, 0
		mov esi, 0
		mov ax, 0
		cmp ax, max
		je Exit //Если макс = 0, то массив выведем без изменений

		Divcycle:
		mov ax, A[esi*2]
		cmp ax, 0
		jge Next //если элемент меньше нуля, то мы нашли отрицательный, иначе  - переход по метке
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
