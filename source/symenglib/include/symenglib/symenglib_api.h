#ifndef SYMENGLIB_API_H
#define SYMENGLIB_API_H

#ifdef _MSC_VER
#   define SYMENGLIB_API_EXPORT_DECLARATION __declspec(dllexport)
#   define SYMENGLIB_API_IMPORT_DECLARATION __declspec(dllimport)
#elif __GNUC__
#	define SYMENGLIB_API_EXPORT_DECLARATION __attribute__ ((visibility ("default")))
#	define SYMENGLIB_API_IMPORT_DECLARATION __attribute__ ((visibility ("default")))
#else
#   define SYMENGLIB_API_EXPORT_DECLARATION
#   define SYMENGLIB_API_IMPORT_DECLARATION
#endif

#ifndef PDBPARSER_STATIC
#ifdef SYMENGLIB_EXPORTS
#   define SYMENGLIB_API SYMENGLIB_API_EXPORT_DECLARATION
#else
#   define SYMENGLIB_API SYMENGLIB_API_IMPORT_DECLARATION
#endif
#else
#   define SYMENGLIB_API
#endif

#ifdef N_DEBUG
#   define IF_DEBUG(statement)
#   define IF_NDEBUG(statement) statement
#else
#   define IF_DEBUG(statement) statement
#   define IF_NDEBUG(statement)
#endif // N_DEBUG

// http://stackoverflow.com/questions/18387640/how-to-deal-with-noexcept-in-visual-studio
#ifndef NOEXCEPT
#   ifdef _MSC_VER
#       define NOEXCEPT
#   else
#       define NOEXCEPT noexcept
#   endif
#endif

#endif // SYMENGLIB_API_H
