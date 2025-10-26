#pragma once

namespace Utils
{
template <typename T> bool IsValidUniquePtr(const T& ptr) { return ptr != nullptr; }
} // namespace Utils
