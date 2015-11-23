#pragma once

#include<string>
extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#ifndef KAGUYA_USE_BOOST
#if __cplusplus >= 201103L
#define KAGUYA_USE_BOOST 0
#else
#define KAGUYA_USE_BOOST 1
#endif
#endif


#if KAGUYA_USE_BOOST
#include <boost/function.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/shared_ptr.hpp>
#if BOOST_VERSION >= 104800
#include <boost/move/move.hpp>
#endif
#else
#include <functional>
#include <tuple>
#include <memory>
#include <utility>

#endif
namespace kaguya
{
	namespace standard
	{
#if KAGUYA_USE_BOOST
		using boost::function;
		using boost::tuple;
		using boost::shared_ptr;
		using boost::get;
#if BOOST_VERSION >= 104800
		using boost::forward;
#else
		template<typename T>T forward(T v) { return v; }
#endif

		std::string to_string(int v)
		{
			char buffer[128] = { 0 };
			snprintf(buffer, sizeof(buffer), "%d", v);
			return buffer;
		}
#else
		using std::function;
		using std::tuple;
		using std::shared_ptr;
		using std::to_string;
		using std::get;
		using std::forward;
#endif
	}

}