#include "lab05.h"
#include <algorithm>
#include <numeric>

void SortByRating(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  if (a.Ratings.empty() && b.Ratings.empty()) return false;
                  if (a.Ratings.empty()) return true;
                  if (b.Ratings.empty()) return false;

                  double avgA = std::accumulate(a.Ratings.begin(), a.Ratings.end(), 0.0) / a.Ratings.size();
                  double avgB = std::accumulate(b.Ratings.begin(), b.Ratings.end(), 0.0) / b.Ratings.size();
                  return avgA > avgB;
              });
}