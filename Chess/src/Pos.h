#pragma once

#include <compare>

struct Pos {
  int x;
  int y;

  Pos() : x(0), y(0) {}
  Pos(int x, int y) : x(x), y(y) {}

  auto operator<=>(const Pos &) const = default;

  Pos operator+(const Pos &other) const {
    return Pos(x + other.x, y + other.y);
  }

  Pos operator-(const Pos &other) const {
    return Pos(x - other.x, y - other.y);
  }

  Pos operator*(int n) const { return Pos(x * n, y * n); }

  Pos operator/(int n) const { return Pos(x / n, y / n); }

  Pos &operator+=(const Pos &other) {
    x += other.x;
    y += other.y;
    return *this;
  }

  Pos &operator-=(const Pos &other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }

  Pos &operator*=(int n) {
    x *= n;
    y *= n;
    return *this;
  }

  Pos &operator/=(int n) {
    x /= n;
    y /= n;
    return *this;
  }
};