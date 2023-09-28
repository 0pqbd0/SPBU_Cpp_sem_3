
#ifndef TASK_2_HW_VECTOR_H_H
#define TASK_2_HW_VECTOR_H_H


#include "ostream"
#include "istream"
#include "string"
#include "cmath"
#include "sstream"

template<class T, size_t N>
class vector_ {
private:
    T x[N];
public:
    vector_() {
        for (size_t i = 0; i < N; ++i) {
            x[i] = T();
        }
    }

    explicit vector_(T *array) {
        for (size_t i = 0; i < N; ++i) {
            x[i] = array[i];
        }
    }

    vector_ &operator+=(const vector_ &c) {
        for (size_t i = 0; i < N; ++i) {
            x[i] += c.x[i];
        }
        return *this;
    }

    vector_ operator+(const vector_ &c) {
        vector_ n = *this;
        n += c;
        return n;
    }

    vector_ &operator-=(const vector_ &c) {
        for (size_t i = 0; i < N; ++i) {
            x[i] -= c.x[i];
        }
        return *this;
    }

    vector_ operator-(const vector_ &c) {
        vector_ n = *this;
        n -= c;
        return n;
    }

    vector_ operator*(const vector_ &c) {
        T result = T();
        for (size_t i = 0; i < N; ++i) {
            result += x[i] * c.x[i];
        }
        return result;
    }

    vector_ &operator*=(const T &c) {
        for (size_t i = 0; i < N; ++i) {
            x[i] *= c;
        }
    }

    vector_ operator*(const T &c) {
        vector_ result = *this;
        result *= c;
        return result;
    }

    vector_ &operator/=(const T &c) {
        for (size_t i = 0; i < N; ++i) {
            x[i] /= c;
        }
    }

    vector_ operator/(const T &c) {
        vector_ result = *this;
        result /= c;
        return result;
    }

    bool operator==(const vector_ &c) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] != c.x[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const vector_ &c) const {
        return *this != c;
    }

    bool operator<(const vector_ &c) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] >= c.x[i]) {
                return true;
            }
        }
        return false;
    }

    bool operator<=(const vector_ &c) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] > c.x[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator>(const vector_ &c) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] >= c.x[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator>=(const vector_ &c) const {
        for (size_t i = 0; i < N; ++i) {
            if (x[i] < c[i]) {
                return false;
            }
        }
        return true;
    }

    vector_ &operator=(const vector_ &c) {
        if (&c == this) {     // <--- Чтобы избежать самоприсваиание
            return *this;
        }
        for (size_t i = 0; i < N; ++i) {
            x[i] = c.x[i];
        }
        return *this;
    }

    vector_ &operator+() {
        return *this;
    }

    vector_ &operator-() {
        for (size_t i = 0; i < N; ++i) {
            x[i] = -x[i];
        }
        return *this;
    }

    T eun() const {
        T result = T();
        for (size_t i = 0; i < N; ++i) {
            result += x[i] * x[i];
        }
        return sqrt(result);
    }

    const T &operator[](size_t index) const {
        return x[index];
    }

    friend std::ostream &operator<<(std::ostream &stream_o, const vector_<T, N> &c) {
        stream_o << "[";
        for (size_t i = 0; i < N; ++i) {
            stream_o << c[i];
            if (i != N - 1) {
                stream_o << ", ";
            }
        }
        stream_o << "]";
        return stream_o;
    }

    friend std::istream &operator>>(std::istream &stream_i, vector_<T, N> &c) {
        T elem;
        for (size_t i = 0; i < N; ++i) {
            stream_i >> elem;
            c.x[i] = elem;
        }
        return stream_i;
    }
};

#endif //TASK_2_HW_VECTOR_H_H






