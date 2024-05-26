#pragma once
#include <map>
#include <iostream>
#include <list>
#include <numeric>
#include <algorithm>


using namespace std;

void  Push_average_value(map <int, Pair>& m_map) {
	if (m_map.size() > 0) {
		int MaxKey = max_element(m_map.begin(), m_map.end(), [](const auto& p1, const auto& p2) {
			return p1.first < p2.first;
			})->first + 1;
		Pair Middle_second = accumulate(m_map.begin(), m_map.end(), Pair(0, 0), [](Pair value, const auto& p) {
			return value + p.second;
			}) / m_map.size();
			m_map[MaxKey] = Middle_second;
			m_map.insert({ MaxKey, Middle_second });
	}
	else {
		cout << "Словарь пуст!\n";
	}
}

void Delete_range_keys(map <int, Pair>& m_map, const double BeginValue, const double EndValue) {
	for (auto p = m_map.begin(); p != m_map.end();) {
		if (BeginValue <= (*p).second && (*p).second <= EndValue) {
			p = m_map.erase(p);
		}
		else {
			p++;
		}
	};
}

void Plus_sum_Min_Max(map <int, Pair>& m_map) {
	if (m_map.size() > 0) {
		Pair MaxValue = max_element(m_map.begin(), m_map.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
			})->second;
		Pair MinValue = min_element(m_map.begin(), m_map.end(), [](const auto& p1, const auto& p2) {
			return p1.second < p2.second;
			})->second;
		for (auto& p : m_map) {
			p.second = p.second + MaxValue + MinValue;
		}
	}
}

void Show_map(const map <int, Pair>& m_map) {
	if (m_map.size() > 0) {
		for (auto& p : m_map) {
			cout << p.first << ") " << p.second << '\n';
		}
	}
	else {
		cout << "Словарь пуст!";
	}
	cout << '\n';
}