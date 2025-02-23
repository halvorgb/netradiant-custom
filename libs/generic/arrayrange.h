/*
   Copyright (C) 2001-2006, William Joseph.
   All Rights Reserved.

   This file is part of GtkRadiant.

   GtkRadiant is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   GtkRadiant is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GtkRadiant; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#pragma once
#include <span>

template<typename _Type, size_t _Extent = std::dynamic_extent>
using Span = std::span<_Type, _Extent>;

using StringArrayRange = Span<char *const>;

inline StringArrayRange makeStringArrayRange(const std::vector<const char*>& vec) {
  static std::vector<char*> temp;
  temp.resize(vec.size());
  for(size_t i = 0; i < vec.size(); ++i) {
      temp[i] = const_cast<char*>(vec[i]);
  }
  return StringArrayRange(temp.data(), temp.size());
}

inline StringArrayRange makeStringArrayRange(const char* const* arr, std::size_t size) {
  static std::vector<char*> temp;
  temp.resize(size);
  for(std::size_t i = 0; i < size; ++i) {
      temp[i] = const_cast<char*>(arr[i]);
  }
  return StringArrayRange(temp.data(), size);
}

// Keep the original array reference version too
template<size_t N>
inline StringArrayRange makeStringArrayRange(const char* const (&arr)[N]) {
  return makeStringArrayRange(arr, N);
}


using StringRange = Span<const char>;
