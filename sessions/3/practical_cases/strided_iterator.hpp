#pragma once

#include <iterator>
#include <type_traits>

template <typename RAIter,
    std::size_t Stride,
    typename Enable = typename std::enable_if<
        std::is_same<std::random_access_iterator_tag,
            typename std::iterator_traits<RAIter>::iterator_category>::value,
        void>::type>
class Strided_iterator {
public:
    using self_type = Strided_iterator;
    using value_type = typename RAIter::value_type;
    using reference = typename RAIter::reference;
    using pointer = typename RAIter::pointer;
    using iterator_category = typename std::random_access_iterator_tag;
    using difference_type = typename RAIter::difference_type;

    Strided_iterator() : _iter(), _end() {
    }

    Strided_iterator(RAIter iter, RAIter end) : _iter(iter), _end(end) {
    }

    Strided_iterator(const Strided_iterator&) = default;
    Strided_iterator& operator=(const Strided_iterator&) = default;

    Strided_iterator(Strided_iterator&& o) : _iter(std::move(o._iter)), _end(std::move(o._end)) {
    }

    Strided_iterator& operator=(Strided_iterator&&) {
        _iter = std::move(o._iter);
        _end = std::move(o._end);
    }

    self_type& operator++() {
        if (std::distance(_iter, _end) <= Stride) {
            _iter = _end;
        } else {
            _iter += Stride;
        }
        return *this;
    }

    self_type operator++(int) {
        const auto tmp = *this;
        ++*this;
        return tmp;
    }

    self_type& operator+=(difference_type d) {
        const auto incr = Stride * d;
        if (std::distance(_iter, _end) <= incr) {
            _iter = _end;
        } else {
            _iter += incr;
        }
        return *this;
    }

    self_type& operator--() {
        _iter -= Stride;
        return *this;
    }

    self_type operator--(int) {
        const auto tmp = *this;
        --*this;
        return tmp;
    }

    self_type& operator-=(difference_type d) {
        const auto decr = Stride * d;
        _iter -= decr;
        return *this;
    }

    reference operator*() const {
        return *_iter;
    }

    pointer operator->() const {
        return &*_iter;
    }

    friend self_type operator+(const self_type& i, difference_type d) {
        auto tmp = i;
        return (tmp += d);
    }

    friend self_type operator+(difference_type d, const self_type& i) {
        auto tmp = i;
        return (tmp += d);
    }

    friend self_type operator-(const self_type& i, difference_type d) {
        auto tmp = i;
        return (tmp -= d);
    }

    friend self_type operator-(difference_type d, const self_type& i) {
        auto tmp = i;
        return (tmp -= d);
    }

    friend void swap(self_type& lhs, self_type& rhs) {
        using std::swap;
        swap(lhs._iter, rhs._iter);
        swap(lhs._end, rhs._end);
    }

    template <typename ItL, typename ItR, std::size_t S>
    friend typename Strided_iterator<ItL, S>::difference_type operator-(
        const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend typename Strided_iterator<ItL, S>::difference_type operator-(
        const Strided_iterator<ItL, S>& l, const ItR& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend typename Strided_iterator<ItL, S>::difference_type operator-(
        const ItL& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator<(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator>(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator<=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator>=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator==(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

    template <typename ItL, typename ItR, std::size_t S>
    friend bool operator!=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r);

private:
    std::tuple<RAIter, RAIter> tie() const {
        return std::tie(_iter, _end);
    }

    RAIter _iter;
    RAIter _end;
};

template <typename ItL, typename ItR, std::size_t S>
typename Strided_iterator<ItL, S>::difference_type operator-(
    const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    const auto diff = (l._iter - r._iter);
    return (diff / static_cast<typename Strided_iterator<ItL, S>::difference_type>(S)) + 1;
}

template <typename ItL, typename ItR, std::size_t S>
typename Strided_iterator<ItL, S>::difference_type operator-(
    const Strided_iterator<ItL, S>& l, const ItR& r) {
    const auto diff = (l._iter - r);
    return (diff / static_cast<typename Strided_iterator<ItL, S>::difference_type>(S)) + 1;
}

template <typename ItL, typename ItR, std::size_t S>
typename Strided_iterator<ItL, S>::difference_type operator-(
    const ItL& l, const Strided_iterator<ItR, S>& r) {
    const auto diff = (l - r._iter);
    return (diff / static_cast<typename Strided_iterator<ItL, S>::difference_type>(S)) + 1;
}

template <typename ItL, typename ItR, std::size_t S>
bool operator<(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() < r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator>(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() > r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator<=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() <= r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator>=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() >= r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator==(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() == r.tie();
}

template <typename ItL, typename ItR, std::size_t S>
bool operator!=(const Strided_iterator<ItL, S>& l, const Strided_iterator<ItR, S>& r) {
    return l.tie() != r.tie();
}
