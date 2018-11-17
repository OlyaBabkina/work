#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport) 
#else
#define MATHFUNCSDLL_API __declspec(dllimport) 
#endif

namespace headercc
{
	extern "C" { __declspec(dllexport) double count(int j, int k, int N, double w, double K, double m1, double m2, double m3, int mirror, int shag); }
}