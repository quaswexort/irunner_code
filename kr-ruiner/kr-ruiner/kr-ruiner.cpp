#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("in.txt"); // обьявление с какого файла списываются данные обьявление файлового потока вводы
    ofstream fout("out.txt"); // обьявление потока вывода
    /*    	if (!fin)
	{   
		return 0;
	}
	if (fin.eof())
	{
		fin.close();
		return 0;
	}*/
    long long n;  //кол-во чисел
    vector<long long> v; //вектор чисел
    vector<long long> v_result; //результирующий вектор
    fin >> n; //ввод числа н
    if ((n < 1) || (n > 10000)) {//проверка на правильность ввода н и на пустоту
        fin.close();
        fout.close();
        return 1;
    }

    long long count; //вводимое число
    while (fin >> count)//пока число вводится запись в конец вектора твоего числа
        v.push_back(count);//(конец)
    for (int i = 1; i < n - 1; i++) {
        if (v.at(i) > v.at(i - 1) && v.at(i) > v.at(i + 1))// функция обраения к итому обращению вектора
            v_result.push_back(i);//в конец результ вектора заносим локальный максимум
    }

    for (int i = 0; i < n; i++) {
        fout << v.at(i);//вывод всех элементов массива в строчку(условие 1)
        if (i == n - 1)
            fout << endl;//если конец массива переходим на новую строку, если нет - пробел между эл
        else
            fout << " ";
    }

    for (int i = v_result.size() - 1; i >= 0; i--) {
        fout << ++v_result.at(i);// в конец выводного файла вывожу индекс + 1
        if (i > 0)
            fout << " ";
    }

    fin.close();
    fout.close();
    return 0;
}

//#include<iostream>
//#include <fstream>
//using namespace std;
//int main()
//{
//	ifstream in("in.txt");
//	if (!in)
//	{
//		return 0;
//	}
//	if (in.eof())
//	{
//		in.close();
//		return 0;
//	}
//	ofstream out("out.txt");
//	long long n = 0, i = 0;
//	in >> n;
//	if ((n < 1) || (n > 10000))
//	{
//		in.close();
//		out.close();
//		return 0;
//	}
//	long long* arr = new long long[n + 1];
//	while (in >> arr[i])
//	{
//		if (i == n)
//		{
//			delete[] arr;
//			in.close();
//			out.close();
//			return 0;
//		}
//		if (abs(arr[i]) > 1000000000)
//		{
//			delete[] arr;
//			in.close();
//			out.close();
//			return 0;
//		}
//		i++; // v konce cikla i == n
//	}
//	in.close();
//	if (i != n)//esli el menshe n
//	{
//		delete[] arr;
//		out.close();
//		return 0;
//	}
//	out << arr[0]; // vivodim 0 el massiva
//	for (long long q = 1; q < n; q++)
//		out << " " << arr[q];
//	out << endl;//vivod pustogo massiva i perehod na novuyu stroky
//	i = n - 2;
//	while (((arr[i] <= arr[i + 1]) || (arr[i] <= arr[i - 1])) && (i > 0))//s konca cikla perviy loc max
//	{
//		i--;
//	}
//	if (i != 0)//esli i = 0 znachit doshli do nachala nichego ne
//	{
//		out << i + 1;
//		for (long long q = i - 1; q > 0; q--)//cikl v kotorom mi idem s konca do nachala i vvivodim indeksi
//		{
//			if ((arr[q] > arr[q + 1]) && (arr[q] > arr[q - 1]))
//				out << " " << q + 1;
//		}
//
//	}
//	delete[] arr;
//	out.close();
//	return 0;
//}

//Markin kr konakh

//Объявить вектор целых чисел, заполнить его случайными числами из отрезка [-5,10] и подсчитать количество положительных элементов.

//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//    vector <int> v;
//    int size_of_vector; 
//    cin >> size_of_vector;
//    for (int i = 0; i < size_of_vector; i++)
//    {
//        v.push_back(rand() % 16 - 5);
//    }
//
//    for (int item : v)
//    {
//        cout << item << " ";
//    }
//
//    cout << endl;
//    int positiveCount = 0; 
//    for (int item : v)
//    {
//        if (item > 0)
//            ++positiveCount;
//    }
//
//    cout << positiveCount;
//    return 0;
//}