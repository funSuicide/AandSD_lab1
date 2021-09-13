#include <iostream>

class Set {
	int *set;
	int cardinality;
public:
	Set() {
		set = 0;
		cardinality = 0;
	}

	Set(int cardinality, int *set) {
		this->cardinality = cardinality;
		this->set = new int[this->cardinality];
		for (int i = 0; i < this->cardinality; i++) {
			this->set[i] = set[i];
		}
	}

	Set(const Set &rhs) {
		cardinality = rhs.cardinality;
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) {
			set[i] = rhs.set[i];
		}

	}

	~Set() {
		delete []set;
		set = 0;
		cardinality = 0;
	}

	int& operator [] (const int index) {
		if (index >= cardinality) throw ("Incorrect access by index");
		else return set[index];
	}

	Set operator = (const Set &rhs) {
		if (this == &rhs) {
			return *this;
		}

		this->~Set();
		cardinality = rhs.cardinality;
		set = new int[cardinality];
		for (int i = 0; i < cardinality; i++) {
			set[i] = rhs.set[i];
		}
		return *this;
	}

	Set operator + (const Set &rhs) {
		Set tmp(*this);
		for (int i = 0; i < rhs.cardinality; i++) {
			bool flag = true;
			for (int j = 0; j < cardinality; j++) {
				if (rhs.set[i] == set[j]) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				tmp = tmp + rhs.set[i];
			}
		}
		return tmp;
	}

	Set operator - (const Set &rhs) {
			Set tmp(*this);
			for (int i = 0; i < rhs.cardinality; i++) {
				for (int j = 0; j < cardinality; j++) {
					if (rhs.set[i] == set[j]) {
						tmp = tmp - rhs.set[i];
						break;
					}
				}
			}
			return tmp;
		}

	Set operator + (const int value) {
			for (int i = 0; i < cardinality; i++) {
				if (set[i] == value) throw ("The specified value already belongs to the set\n");
			}
			Set tmp;
			tmp.cardinality = this->cardinality + 1;
			tmp.set = new int[tmp.cardinality];
			for (int i = 0; i < tmp.cardinality - 1; i++)
			{
				tmp.set[i] = set[i];
			}
			tmp.set[tmp.cardinality - 1] = value;
			return tmp;
		}

	Set operator - (const int value) {
			int counter = -1;
			for (int i = 0; i < cardinality; i++) {
				if (set[i] == value) counter = i;
			}
			if (counter != -1) {
				Set tmp;
				tmp.cardinality = this->cardinality - 1;
				tmp.set = new int[tmp.cardinality];
				for (int i = 0; i < counter; i++)
				{
					tmp.set[i] = set[i];
				}
				for (int i = counter + 1; i < tmp.cardinality; i++)
				{
					tmp.set[i] = set[i];
				}
				return tmp;
			}
			else throw ("This element is missing in the set\n");
		}

	friend std::ostream& operator << (std::ostream &out, const Set &rhs) {
		out << "Cardinality is " << rhs.cardinality << "\n";
		for (int i = 0; i < rhs.cardinality; i++) {
			out << rhs.set[i] << " ";
		}
		return out;
	}

	friend Set IntersectionSets(const Set &rhs1, const Set &rhs2);

};

Set IntersectionSets(const Set &rhs1, const Set &rhs2) {
	Set tmp;
	for (int i = 0; i < rhs1.cardinality; i++) {
		for (int j = 0; j < rhs2.cardinality; j++) {
			if (rhs1.set[i] == rhs2.set[j]) {
				tmp = tmp + rhs1.set[i];
				break;
			}
		}
	}
	return tmp;
}