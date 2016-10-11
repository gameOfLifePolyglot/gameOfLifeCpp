
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

template<class T, typename Predicate>
std::set<T> filter(const std::set<T> &container, Predicate predicate) {
    std::set<T> results;
    std::copy_if(container.begin(), container.end(), std::inserter(results, results.end()), predicate);
    return results;
}

template<typename T, typename Func>
auto map(const T &iterable, Func &&func) ->
std::set<decltype(func(std::declval<typename T::value_type>()))> const {
    typedef decltype(func(std::declval<typename T::value_type>())) value_type;
    typedef std::set<value_type> result_type;

    result_type res;
    std::transform(iterable.begin(), iterable.end(), std::inserter(res, res.end()), std::forward<Func>(func));
    return res;
}

template<template<typename...> class R=std::set,
        typename Top,
        typename Sub = typename Top::value_type>
R<typename Sub::value_type> flatten(Top const &all) {
    using std::begin;
    using std::end;

    R<typename Sub::value_type> accum;

    for (auto &sub : all)
        std::copy(begin(sub), end(sub), std::inserter(accum, end(accum)));

    return accum;
}

template<typename Collection>
std::set<typename Collection::value_type> merge(Collection &first, Collection &second) {
    std::set<typename Collection::value_type> accum;
    std::copy(first.begin(), first.end(), std::inserter(accum, end(accum)));
    std::copy(second.begin(), second.end(), std::inserter(accum, end(accum)));
    return accum;
}