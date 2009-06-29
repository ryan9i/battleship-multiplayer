/**********************************************************
encoding.h
***********************************************************/
#ifndef ENCODING_H_
#define ENCODING_H_

class encoding
{
	public:
		int encrypt(int Message);
		int decrypt(int Message);
		int generateRequiredValues();
		int GCD(int a, int b);
		int congruence ( int a, int b, int c, bool *error );
		int i4_gcd ( int i, int j );
		void i4_swap ( int *i, int *j );
		int i4_sign ( int i );
		int i4_max ( int i1, int i2 );
		int i4_min ( int i1, int i2 );
};

#endif ENCODING_H_