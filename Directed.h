#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class graph {
public:
	struct Element {

		int key;
		T data;
		Element* next;

		Element(T val) : key(0), data(val), next(nullptr) {}
	};

	//количество элементов
	size_t count;

	//матрица связей между ребрами
	vector<vector<int>> matrix;

	//указатели на элементы
	Element* current, * first;

	graph() {
		count = 0;
	}

	~graph() {
		matrix.clear();
	}


	//добавление элемента
	void add_element(T val) {


		if (matrix.empty()) {

			count++;
			matrix.resize(count);
			for (int i = 0; i < count; i++) {
				matrix[i].resize(count);
				for (int j = 0; j < count; j++) {
					if (j == count - 1) {
						matrix[i][j] = 0;
					}
				}
			}
			Element* e = new Element(val);
			e->key = 0;
			first = e;
			current = e;

		}
		else {
			vector<vector<T>> new_m;
			count++;
			new_m.resize(count);
			for (int i = 0; i < count - 1; i++) {
				new_m[i].resize(count);
				for (int j = 0; j < count - 1; j++) {
					new_m[i][j] = matrix[i][j];
				}
			}
			for (int i = count - 1; i < count; i++) {
				new_m[i].resize(count);
				for (int j = 0; j < count; j++) {
					new_m[i][j] = 0;
				}
			}
			Element* e = new Element(val);
			e->key = count - 1;
			(current)->next = e;
			(current) = e;
			matrix = new_m;
		}
	}

	//добавление дуги
	void add_edge(T a, T b) {
		Element* el_a = find(a);
		Element* el_b = find(b);

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if ((i == el_a->key) && (j == el_b->key)) {
					int num = matrix[i][j];
					matrix[i][j] = num + 1;
				}
			}
		}
	}

	//удаление ребра
	void remove_edge(T a, T b) {
		Element* el_a = find(a);
		Element* el_b = find(b);

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if ((i == el_a->key) && (j == el_b->key)) {
					matrix[i][j] = 0;
				}
			}
		}
	}

	//удаление элемента
	void remove_element(T val) {
		Element* p = first;
		Element* q = first;
		Element* s = first;

		while (p) {
			if (p->data == val) {
				s = p;
				q->next = p->next;

				break;
			}
			else {
				q = p;
				p = p->next;
			}
		}


		auto num = s->key;

		for (size_t i = 0; i < matrix.size(); i++)
			matrix[i].erase(matrix[i].begin()+num);
		matrix.erase(matrix.begin()+num);

		count = matrix.size();

	}



	//возвращает нужный элемент
	Element* find(T val) {
		Element* p = first;
		while (p && p->data != val) p = p->next;
		return (p && p->data == val) ? p : nullptr;
	}

	//вывод data 
	void print_element() {
		Element* q = first;
		while (q) {
			cout << q->data << " ";
			q = q->next;
		}
		cout << endl;
	}

	//вывод на экран матрицы
	void print() {
		cout << count << endl;
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
