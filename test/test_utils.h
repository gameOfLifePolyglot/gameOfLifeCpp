
#include <algorithm>
#include <iterator>

template<class TInputIterator, class T>
inline
bool contains(TInputIterator first, TInputIterator last, const T &value) {
    return std::find(first, last, value) != last;
}

template<class TContainer, class T>
inline
bool contains(const TContainer &container, const T &value) {
    return contains(std::begin(container), std::end(container), value);
}

template<class T>
inline
bool contains(const std::set<T> &container, const T &value) {
    return container.find(value) != container.end();
}

template<class T>
inline
bool containsAll(const std::set<T> &container, const std::set<T> &values) {
    for (auto const &value: values) {
        if (!contains(container, value)) {
            return false;
        }
    }
    return true;
}