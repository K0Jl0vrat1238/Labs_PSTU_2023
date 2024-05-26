#pragma once
#include<iostream>
#include <list>
#include <numeric>
#include <algorithm>
#include<Queue>
#include"Pair.h"

using namespace std;

list<Pair> priority_queueTolist(priority_queue<Pair>& m_priority_queue) {
	priority_queue <Pair> tmp_priority_queue = m_priority_queue;
	list <Pair> m_list;
	while (tmp_priority_queue.size() > 0) {
		m_list.push_back(tmp_priority_queue.top());
		tmp_priority_queue.pop();
	}
	return m_list;
}

void Push_average_value(priority_queue<Pair>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		Pair Average = accumulate(m_list.begin(), m_list.end(), Pair(0, 0));
		Average.set_first(Average.get_first() / m_list.size());
		Average.set_second(Average.get_second() / m_list.size());
		m_priority_queue.push(Average);
	}
	else {
		cout << "Очередь пуста!\n";
	}
}

void Delete_range_keys(priority_queue<Pair>& m_priority_queue, const double BeginValue, const double EndValue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		auto i = remove_if(m_list.begin(), m_list.end(), [BeginValue, EndValue](Pair p) {
			return (BeginValue <= p.get_first() && p.get_first() <= EndValue) && (BeginValue <= p.get_second() && p.get_second() <= EndValue);
			});
		m_priority_queue = {};
		if (i != m_list.begin()) {
			for_each(m_list.begin(), i--, [&m_priority_queue](Pair p) {
				m_priority_queue.push(p);
				});
		}
	}
}

void Plus_sum_Min_Max(priority_queue<Pair>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		m_priority_queue = {};
		Pair max = *max_element(m_list.begin(), m_list.end());
		Pair min = *min_element(m_list.begin(), m_list.end());
		for (Pair& c : m_list) {
			m_priority_queue.push(c + max + min);
		}
	}
}

void Show_priority_queue(priority_queue<Pair>& m_priority_queue) {
	if (m_priority_queue.size() > 0) {
		list <Pair> m_list = priority_queueTolist(m_priority_queue);
		for_each(m_list.begin(), m_list.end(), [](Pair p) {
			cout << p << '\n';
			});
	}
	else {
		cout << "Очередь пуста!";
	}
	cout << '\n';
}