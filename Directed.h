#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

template <class T>
class graph {
public:


	typedef T value_type;
	struct Element {

		int key;
		value_type data;
		Element* next;

		Element(T val) : key(0), data(val), next(nullptr) {}
	};



	//----------------------------------ИТЕРАТОР------------------------------------
	template<typename T>
	class vv_iterator : public std::iterator<std::bidirectional_iterator_tag, T> {
	private:
		vv_iterator(std::vector<std::vector<T>>* _vv,
			std::size_t _idxOuter,
			std::size_t _idxInner)
			: vv(_vv), idxOuter(_idxOuter), idxInner(_idxInner) {}

		std::vector<std::vector<int>>* vv = nullptr;
		std::size_t idxOuter = 0;
		std::size_t idxInner = 0;
	public:

		static vv_iterator<T> begin(std::vector<std::vector<T>>& vv) {
			return vv_iterator(&vv, 0, 0);
		}
		static vv_iterator<T> end(std::vector<std::vector<T>>& vv) {
			return vv_iterator(&vv, vv.size(), 0);
		}

		vv_iterator() = default;

		
		// ++ префиксный
		vv_iterator& operator++()
		{
			//Если не достигли конца внутреннего вектора
			if (idxInner + 1 < (*vv)[idxOuter].size())
			{
				//идем к следующему элементу
				++idxInner;
			}
			else
			{
				//в обратном случае - перебираем внутренние векторы, пока
				//не дойдем до непустого или до конца
				do
				{
					++idxOuter;
				} while (idxOuter < (*vv).size() && (*vv)[idxOuter].empty());

				//Пере ходим в начало вектора
				idxInner = 0;
			}
			return *this;
		}
		// -- префиксный
		vv_iterator& operator--()
		{
			// Если не начало
			if (idxInner > 0)
			{
				// идем к предыдущему
				--idxInner;
			}
			else
			{
				// тот же принцип, что и у ++
				do
				{
					--idxOuter;
				} while ((*vv)[idxOuter].empty());

				// перемещаемся в конец
				idxInner = (*vv)[idxOuter].size() - 1;
			}
			return *this;
		}
		// ++ постфиксный
		vv_iterator operator++(int)
		{
			T retval = *this;
			++(*this);
			return retval;
		}
		// -- постфксный
		vv_iterator operator--(int)
		{
			T retval = *this;
			--(*this);
			return retval;
		}

		//==
		bool operator==(const vv_iterator& other) const
		{
			return other.vv == vv && other.idxOuter == idxOuter && other.idxInner == idxInner;
		}

		//!=
		bool operator!=(const vv_iterator& other) const
		{
			return !(*this == other);
		}

		//*()
		const T& operator*() const
		{
			return *this;
		}
		T& operator*()
		{
			return (*vv)[idxOuter][idxInner];
		}

		//->()
		const T& operator->() const
		{
			return *this;
		}
		T& operator->()
		{
			return *this;
		}

	};

	//количество элементов
	size_t count;

	//матрица смежности
	vector<vector<T>> matrix;

	//указатели на элементы
	Element* current, * first;

	graph() {
		count = 0;
	}

	~graph() {
		matrix.clear();
	}

	//возвращает количество вершин
	size_t get_vertexes() {
		return count;
	}

	//возвращает количество ребер
	int get_arcs() {
		int amount = 0;
		for (size_t i = 0; i < count; i++)
		{
			for (size_t j = 0; j < count; j++)
			{
				if (matrix[i][j] == 1)
					amount++;
			}

		}
		return amount;
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

	//проверка принадлежности вершины графу
	void find_vertex(T val) {
		Element* p = find(val);
		if (p)
			cout << "Vertex " << val << " belongs to the matrix" << endl;
		else
			cout << "Vertex doesn't belong to the matrix" << endl;
	}

	//проверка принадлежности ребра графу
	void find_edge(T a, T b) {
		Element* el_a = find(a);
		Element* el_b = find(b);
		int k = 0;

		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				if ((i == el_a->key) && (j == el_b->key) && matrix[i][j] == 1) {
					cout << "Edge between " << a << " and " << b << " belongs to the matrix" << endl;
					k++;
				}
			}
		}
		if (k == 0)
			cout << "Edge doesn't belong to the matrix" << endl;
	}

	//вычисление степени вершины
	int vertex_degree(T val) {
		int degree = 0;
		Element* p = find(val);

		int x = p->key;

		for (size_t i = 0; i < count; i++)
		{
			if (matrix[x][i] == 1)
				degree++;
		}

		for (size_t i = 0; i < count; i++)
		{
			if (matrix[i][x] == 1)
				degree++;
		}
		return degree;
	}

	//степень ребра
	int edge_degree(T a, T b) {
		int degree = 0;
		Element* p1 = find(a);
		Element* p2 = find(b);
		int x = p1->key;
		int y = p2->key;

		if (matrix[x][y] == 1)
			degree++;
		if (matrix[y][x] == 1)
			degree++;

		return degree;
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
		for (const auto& v : matrix)
		{
			for (auto i : v)
				cout << i << " ";
			cout << "\n";
		}
	}


	//вывод на экран обратной матрицы
	void print_reverse() {
		reverse(vv_iterator<T>::begin(matrix), vv_iterator<T>::end(matrix));
		for (const auto& v : matrix)
		{
			for (auto i : v)
				cout << i << " ";
			cout << "\n";
		}
	}

	//---------------------------ПЕРЕГРУЗКА ОПЕРАТОРОВ----------------
	//оператор присваивания
	graph& operator= (const graph& g) {
		count = g.count;
		matrix = g.matrix;
		return *this;
	}

	//оператор сравнения
	friend bool operator == (const graph g1, const graph g2) {
		return (g1.count == g2.count && g1.matrix == g2.matrix);
	}

	//операторы неравенства
	friend bool operator!= (const graph& g1, const graph& g2) {
		return !(g1 == g2);
	}

	//оператор "больше"
	friend bool operator > (const graph& g1, const graph& g2) {
		return (g1.count > g2.count);
	}

	//оператор "меньше"
	friend bool operator < (const graph g1, const graph g2) {
		return (g1.count < g2.count);
	}

	//оператор "больше-равно"
	friend bool operator >= (const graph g1, const graph g2) {
		return (g1.count >= g2.count);
	}

	//оператор "меньше-равно"
	friend bool operator <= (const graph g1, const graph g2) {
		return (g1.count <= g2.count);
	}

	//перегрузка потока вывода
	friend ostream& operator << (ostream& os, const graph& g) {
		for_each(g.matrix.begin(), g.matrix.end(), [&os](const vector<T>& vec) {copy(vec.begin(), vec.end(), ostream_iterator<T>(os, " ")); std::cout << '\n'; });
		return os;
	}
};
