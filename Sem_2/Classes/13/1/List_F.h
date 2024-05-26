#pragma once
#include <list>
#include <numeric>
#include <algorithm>
#include"Pair.h"


void Show_list(const list<Pair>& m_list) {
	if (m_list.size() > 0) {
		for_each(m_list.begin(), m_list.end(), [](Pair p) {
			cout << p << endl;
			});
	}
	else {
		cout << "Список пуст!!";
	}
	cout << '\n';
}

void Push_average_value(list<Pair>& m_list) {
	if (m_list.size() > 0) {
		Pair Average = accumulate(m_list.begin(), m_list.end(), Pair(0, 0));
		Average.set_first(Average.get_first() / m_list.size());
		Average.set_second(Average.get_second() / m_list.size());
		m_list.push_back(Average);
	}
	else {
		cout << "Список пуст!!\n";
	}
}

void Delete_range_keys(list<Pair>& m_list, const double Begin_value, const double End_value) {
	auto i = remove_if(m_list.begin(), m_list.end(), [Begin_value, End_value](Pair p) {
		return ((Begin_value <= p.get_first() && p.get_first() <= End_value) && (Begin_value <= p.get_second() && p.get_second() <= End_value));
		});
	m_list.erase(i, m_list.end());
}

void Plus_sum_Min_Max(list<Pair>& m_list) {
	if (m_list.size() > 0) {
		Pair max = *max_element(m_list.begin(), m_list.end());
		Pair min = *min_element(m_list.begin(), m_list.end());
		for (Pair& c : m_list) {
			c + max + min;
		}
	}
}