/******************************************************************************\
 *           ___        __                                                    *
 *          /\_ \    __/\ \                                                   *
 *          \//\ \  /\_\ \ \____    ___   _____   _____      __               *
 *            \ \ \ \/\ \ \ '__`\  /'___\/\ '__`\/\ '__`\  /'__`\             *
 *             \_\ \_\ \ \ \ \L\ \/\ \__/\ \ \L\ \ \ \L\ \/\ \L\.\_           *
 *             /\____\\ \_\ \_,__/\ \____\\ \ ,__/\ \ ,__/\ \__/.\_\          *
 *             \/____/ \/_/\/___/  \/____/ \ \ \/  \ \ \/  \/__/\/_/          *
 *                                          \ \_\   \ \_\                     *
 *                                           \/_/    \/_/                     *
 *                                                                            *
 * Copyright (C) 2011-2013                                                    *
 * Dominik Charousset <dominik.charousset@haw-hamburg.de>                     *
 *                                                                            *
 * This file is part of libcppa.                                              *
 * libcppa is free software: you can redistribute it and/or modify it under   *
 * the terms of the GNU Lesser General Public License as published by the     *
 * Free Software Foundation; either version 2.1 of the License,               *
 * or (at your option) any later version.                                     *
 *                                                                            *
 * libcppa is distributed in the hope that it will be useful,                 *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 * See the GNU Lesser General Public License for more details.                *
 *                                                                            *
 * You should have received a copy of the GNU Lesser General Public License   *
 * along with libcppa. If not, see <http://www.gnu.org/licenses/>.            *
\******************************************************************************/


#ifndef CPPA_TO_STRING_HPP
#define CPPA_TO_STRING_HPP

#include <type_traits>

#include "cppa/atom.hpp" // included for to_string(atom_value)
#include "cppa/actor.hpp"
#include "cppa/group.hpp"
#include "cppa/object.hpp"
#include "cppa/channel.hpp"
#include "cppa/node_id.hpp"
#include "cppa/anything.hpp"
#include "cppa/any_tuple.hpp"
#include "cppa/intrusive_ptr.hpp"
#include "cppa/abstract_group.hpp"
#include "cppa/message_header.hpp"
#include "cppa/uniform_type_info.hpp"

namespace std { class exception; }

namespace cppa {

namespace detail {

std::string to_string_impl(const void* what, const uniform_type_info* utype);

template<typename T>
inline std::string to_string_impl(const T& what) {
    return to_string_impl(&what, uniform_typeid<T>());
}

} // namespace detail

inline std::string to_string(const any_tuple& what) {
    return detail::to_string_impl(what);
}

inline std::string to_string(const message_header& what) {
    return detail::to_string_impl(what);
}

inline std::string to_string(const actor& what) {
    return detail::to_string_impl(what);
}

inline std::string to_string(const actor_addr& what) {
    return detail::to_string_impl(what);
}

inline std::string to_string(const group& what) {
    return detail::to_string_impl(what);
}

inline std::string to_string(const channel& what) {
    return detail::to_string_impl(what);
}

// implemented in node_id.cpp
std::string to_string(const node_id& what);

// implemented in node_id.cpp
std::string to_string(const node_id_ptr& what);

inline std::string to_string(const object& what) {
    return detail::to_string_impl(what.value(), what.type());
}

/**
 * @brief Converts @p e to a string including the demangled type of e
 *        and @p e.what().
 */
std::string to_verbose_string(const std::exception& e);

} // namespace cppa

#endif // CPPA_TO_STRING_HPP
