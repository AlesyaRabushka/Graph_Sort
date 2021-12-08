#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class graph {
public:
	typedef T value_type;
	struct Element {
		
		int key;
		value_type data;
		Element* next;

		Element(value_type val) : key(0), data(val), next(nullptr) {}
	};

	//количесвто элементов
	size_t count;
	//матрица связей между ребрами
	vector<vector<int>> matrix;
	//указатели на элементы
	Element* current, *first;

	graph() {
		count = 0;
	}

	~graph() {
		matrix.clear();
	}
	

	//добавление элемента
	void add_element(value_type val) {
		
		if (matrix.empty()) {
			
			count++;
			matrix.resize(count);
			for (int i = 0; i < count; i++) {
				matrix[i].resize(count);
				for (int j = 0; j < count; j++) {
					matrix[i][j] = 0;
				}
			}
			Element* e = new Element(val);
			e->key = 0;
			first = e;
			current = e;
			
		}
		else {
			count++;
			matrix.resize(count);
			for (int i = 0; i < count; i++) {
				matrix[i].resize(count);
				for (int j = 0; j < count; j++) {
					matrix[i][j] = 0;
				}
			}
			Element* e = new Element(val);
			e->key = count - 1;
			(current)->next = e;
			(current) = e;
		}
	}

	//добавление дуги
	void add_edge(value_type a, value_type b) {
		Element* el_a = find(a);
		Element* el_b = find(b);
		
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if ((i == el_a->key) && (j == el_b->key)) {
					int num = matrix[i][j];
					matrix[i][j] = num+1;
				}
			}
		}
	}

	//удаление ребра
	void remove_edge(value_type a, value_type b) {
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
	void remove_element(value_type val) {
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

		
		//изменить матрицу нададаададад
		vector<vector<int>> new_m;
		
		cout << "--" << s->key << endl;
		auto num = s->key;
		/*new_m.resize(count);

		for (int i = 0; i < count; i++) {
			new_m[i].resize(count);
			if (i == s->key) {
				i++;
				for (int j = 0; j < count; j++) {
					new_m[i][j] = matrix[i+1][j];
				}
			}
			else {
				for (int j = 0; j < count; j++) {
					new_m[i][j] = matrix[i][j];
				}
			}
		}
		count--;
		new_m.erase(s->key);
		
		matrix = new_m;*/
		
		for (int i = 0; i < count; i++) {
			matrix[i].resize(count);
			if (i == num) {
				for (int j = 0; j < count; j++) {
					matrix[i][j] = -1;
				}
			}
		}

		for (int i = 0; i < count; i++) {
			matrix[i].resize(count);
			for (int j = 0; j < count; j++) {
				if (j == num) {
					matrix[i][j] = -1;
				}
			}
		}

		/*auto iter = matrix.begin();
		matrix.erase(iter + num);
		for (int i = 0; i < count; i++) {
			matrix.resize(count);
			
			for (int j = 0; j < count; j++) {
				if (j == num) {
					auto iter1 = matrix[i].begin();
					matrix[i][j] == 0;
				}
			}
		}*/
		//count--;
	}

	

	//возвращает нужный элемент
	Element* find(value_type val) {
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
