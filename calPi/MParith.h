#include "nr3.h"
#include "fourier.h"
struct MParith {
//	Multiple precision arithmetic operations done on character strings, interpreted as radix 256
	//numbers with the radix point after the first digit.Implementations for the simpler operations
	//are listed here.
	void mpadd(VecUchar_O &w, VecUchar_I &u, VecUchar_I &v) {
		//Adds the unsigned radix 256 numbers u and v, yielding the unsigned result w.To achieve
		//	the full available accuracy, the array w must be longer, by one element, than the shorter of
		//	the two arrays u and v.
			Int j, n = u.size(), m = v.size(), p = w.size();
		Int n_min = MIN(n, m), p_min = MIN(n_min, p - 1);
		Uint ireg = 0;
		for (j = p_min - 1; j >= 0; j--) {
			ireg = u[j] + v[j] + hibyte(ireg);
			w[j + 1] = lobyte(ireg);
		}
		w[0] = hibyte(ireg);
		if (p > p_min + 1)
		for (j = p_min + 1; j<p; j++) w[j] = 0;
	}
	void mpsub(Int &is, VecUchar_O &w, VecUchar_I &u, VecUchar_I &v) {
		//Subtracts the unsigned radix 256 number v from u yielding the unsigned result w.If the
		//	result is negative(wraps around), is is returned as 1; otherwise it is returned as 0. To
		//	achieve the full available accuracy, the array w must be as long as the shorter of the two
		//	arrays u and v.
			Int j, n = u.size(), m = v.size(), p = w.size();
		Int n_min = MIN(n, m), p_min = MIN(n_min, p - 1);
		Uint ireg = 256;
		for (j = p_min - 1; j >= 0; j--) {
			ireg = 255 + u[j] - v[j] + hibyte(ireg);
			w[j] = lobyte(ireg);
		}
		is = hibyte(ireg) - 1;
		if (p > p_min)
		for (j = p_min; j<p; j++) w[j] = 0;
	}
	void mpsad(VecUchar_O &w, VecUchar_I &u, const Int iv) {
	//	Short addition : The integer iv(in the range 0  iv  255) is added to the least significant
	//		radix position of unsigned radix 256 number u, yielding result w.To ensure that the result
	//		does not require two digits before the radix point, one may first right - shift the operand u
	//		so that the first digit is 0, and keep track of multiples of 256 separately.
			Int j, n = u.size(), p = w.size();
		Uint ireg = 256 * iv;
		for (j = n - 1; j >= 0; j--) {
			ireg = u[j] + hibyte(ireg);
			if (j + 1 < p) w[j + 1] = lobyte(ireg);
		}
		w[0] = hibyte(ireg);
		for (j = n + 1; j<p; j++) w[j] = 0;
	}
	void mpsmu(VecUchar_O &w, VecUchar_I &u, const Int iv) {
	//	Short multiplication : The unsigned radix 256 number u is multiplied by the integer iv(in
	//		the range 0  iv  255), yielding result w.To ensure that the result does not require two
	//		digits before the radix point, one may first right - shift the operand u so that the first digit
	//		is 0, and keep track of multiples of 256 separately.
			Int j, n = u.size(), p = w.size();
		Uint ireg = 0;
		for (j = n - 1; j >= 0; j--) {
			ireg = u[j] * iv + hibyte(ireg);
			if (j < p - 1) w[j + 1] = lobyte(ireg);
		}
		w[0] = hibyte(ireg);
		for (j = n + 1; j<p; j++) w[j] = 0;
	}
	void mpsdv(VecUchar_O &w, VecUchar_I &u, const Int iv, Int &ir) {
//		Short division : The unsigned radix 256 number u is divided by the integer iv(in the range
//			0  iv  255), yielding a quotient w and a remainder ir(with 0  ir  255).To achieve
//			the full available accuracy, the array w must be as long as the array u.
			Int i, j, n = u.size(), p = w.size(), p_min = MIN(n, p);
		ir = 0;
		for (j = 0; j<p_min; j++) {
			i = 256 * ir + u[j];
			w[j] = Uchar(i / iv);
			ir = i % iv;
		}
		if (p > p_min)
		for (j = p_min; j<p; j++) w[j] = 0;
	}
	void mpneg(VecUchar_IO &u) {
//		Ones - complement negate the unsigned radix 256 number u.
			Int j, n = u.size();
		Uint ireg = 256;
		for (j = n - 1; j >= 0; j--) {
			ireg = 255 - u[j] + hibyte(ireg);
			u[j] = lobyte(ireg);
		}
	}
	void mpmov(VecUchar_O &u, VecUchar_I &v) {
	//	Move the unsigned radix 256 number v into u.To achieve full accuracy, the array v must
	//		be as long as the array u.
			Int j, n = u.size(), m = v.size(), n_min = MIN(n, m);
		for (j = 0; j<n_min; j++) u[j] = v[j];
		if (n > n_min)
		for (j = n_min; j<n - 1; j++) u[j] = 0;
	}
	void mplsh(VecUchar_IO &u) {
	//	Left - shift digits of unsigned radix 256 number u.The final element of the array is set to 0.
			Int j, n = u.size();
		for (j = 0; j<n - 1; j++) u[j] = u[j + 1];
		u[n - 1] = 0;
	}
	Uchar lobyte(Uint x) { return (x & 0xff); }
	Uchar hibyte(Uint x) { return ((x >> 8) & 0xff); }
	//The following, more complicated, methods have discussion and implementation below.
		void mpmul(VecUchar_O &w, VecUchar_I &u, VecUchar_I &v);
	void mpinv(VecUchar_O &u, VecUchar_I &v);
	void mpdiv(VecUchar_O &q, VecUchar_O &r, VecUchar_I &u, VecUchar_I &v);
	void mpsqrt(VecUchar_O &w, VecUchar_O &u, VecUchar_I &v);
	void mp2dfr(VecUchar_IO &a, string &s);
	string mppi(const Int np);
};







void MParith::mpmul(VecUchar_O &w, VecUchar_I &u, VecUchar_I &v) {
//	mparith.h
//		Uses fast Fourier transform to multiply the unsigned radix 256 integers u[0..n - 1] and v[0..m - 1],
//		yielding a product w[0..n + m - 1].
		const Doub RX = 256.0;
	Int j, nn = 1, n = u.size(), m = v.size(), p = w.size(), n_max = MAX(m, n);
	Doub cy, t;
	while (nn < n_max) nn <<= 1; //Find the smallest usable power of 2 for the transform.
		nn <<= 1;
	VecDoub a(nn, 0.0), b(nn, 0.0);
	for (j = 0; j<n; j++) a[j] = u[j];// Move U and V to double precision floating arrays.
	for (j = 0; j<m; j++) b[j] = v[j];
	realft(a, 1); //Perform the convolution : First, the two Fourier trans
	realft(b, 1); //forms.
		b[0] *= a[0]; //Then multiply the complex results(real and imagi
		b[1] *= a[1]; //nary parts).
			for (j = 2; j<nn; j += 2) {
				b[j] = (t = b[j])*a[j] - b[j + 1] * a[j + 1];
				b[j + 1] = t*a[j + 1] + b[j + 1] * a[j];
			}
			realft(b, -1); //Then do the inverse Fourier transform.
				cy = 0.0; //Make a final pass to do all the carries.
			for (j = nn - 1; j >= 0; j--) {
				t = b[j] / (nn >> 1) + cy + 0.5; //The 0.5 allows for roundoff error.
					cy = Uint(t / RX);
				b[j] = t - cy*RX;
			}
			if (cy >= RX) throw("cannot happen in mpmul");
			for (j = 0; j<p; j++) w[j] = 0;
			w[0] = Uchar(cy); //Copy answer to output.
			for (j = 1; j<MIN(n + m, p); j++) w[j] = Uchar(b[j - 1]);
}


void MParith::mpinv(VecUchar_O &u, VecUchar_I &v) {
//	Character string v[0..m - 1] is interpreted as a radix 256 number with the radix point after
//		(nonzero) v[0]; u[0..n - 1] is set to the most significant digits of its reciprocal, with the radix
//		point after u[0].
		const Int MF = 4;
	const Doub BI = 1.0 / 256.0;
	Int i, j, n = u.size(), m = v.size(), mm = MIN(MF, m);
	Doub fu, fv = Doub(v[mm - 1]);
	VecUchar s(n + m), r(2 * n + m);
	for (j = mm - 2; j >= 0; j--) {
		//Use ordinary floating arithmetic to get an initial
			fv *= BI; //approximation.
			fv += v[j];
	}
	fu = 1.0 / fv;
	for (j = 0; j<n; j++) {
		i = Int(fu);
		u[j] = Uchar(i);
		fu = 256.0*(fu - i);
	}
	for (;;) {
		//Iterate Newton¡¯s rule to convergence.
			mpmul(s, u, v);// Construct 2 UV in S.
			mplsh(s);
		mpneg(s);
		s[0] += Uchar(2);// Multiply SU into U.
			mpmul(r, s, u);
		mplsh(r);
		mpmov(u, r);
		for (j = 1; j<n - 1; j++)// If fractional part of S is not zero, it has not
		if (s[j] != 0) break; //converged to 1.
		if (j == n - 1) return;
	}
}


void MParith::mpdiv(VecUchar_O &q, VecUchar_O &r, VecUchar_I &u, VecUchar_I &v) {
//	Divides unsigned radix 256 integers u[0..n - 1] by v[0..m - 1](with m  n required), yielding a
//		quotient q[0..n - m] and a remainder r[0..m - 1].
		const Int MACC = 1;
	Int i, is, mm, n = u.size(), m = v.size(), p = r.size(), n_min = MIN(m, p);
	if (m > n) throw("Divisor longer than dividend in mpdiv");
	mm = m + MACC;
	VecUchar s(mm), rr(mm), ss(mm + 1), qq(n - m + 1), t(n);
	mpinv(s, v); //Set S D 1 = V .
		mpmul(rr, s, u); //Set Q D SU.
		mpsad(ss, rr, 1);
		mplsh(ss);
		mplsh(ss);
		mpmov(qq, ss);
		mpmov(q, qq);
		mpmul(t, qq, v); //Multiply and subtract to get the remainder.
			mplsh(t);
		mpsub(is, t, u, t);
		if (is != 0) throw("MACC too small in mpdiv");
		for (i = 0; i<n_min; i++) r[i] = t[i + n - m];
		if (p>m) for (i = m; i<p; i++) r[i] = 0;
}



void MParith::mpsqrt(VecUchar_O &w, VecUchar_O &u, VecUchar_I &v) {
//	mparith.h
//		Character string v[0..m - 1] is interpreted as a radix 256 number with the radix point after
//		v[0]; w[0..n - 1] is set to its square root(radix point after w[0]), and u[0..n - 1] is set to the
//		reciprocal thereof(radix point before u[0]).w and u need not be distinct, in which case they
//		are set to the square root.
		const Int MF = 3;
	const Doub BI = 1.0 / 256.0;
	Int i, ir, j, n = u.size(), m = v.size(), mm = MIN(m, MF);
	VecUchar r(2 * n), x(n + m), s(2 * n + m), t(3 * n + m);
	Doub fu, fv = Doub(v[mm - 1]);
	for (j = mm - 2; j >= 0; j--) {
	//	Use ordinary floating arithmetic to get an initial ap
		fv	*= BI;// proximation.
			fv += v[j];
	}
	fu = 1.0 / sqrt(fv);
	for (j = 0; j<n; j++) {
		i = Int(fu);
		u[j] = Uchar(i);
		fu = 256.0*(fu - i);
	}
	for (;;) {
	//	Iterate Newton¡¯s rule to convergence.
			mpmul(r, u, u); //Construct S D .3 VU2 /= 2.
			mplsh(r);
		mpmul(s, r, v);
		mplsh(s);
		mpneg(s);
		s[0] += Uchar(3);
		mpsdv(s, s, 2, ir);
		for (j = 1; j<n - 1; j++) {
//			If fractional part of S is not zero, it has not con
			if(s[j] != 0) {
				               //verged to 1.
					mpmul(t, s, u); //Replace U by SU.
					mplsh(t);
				mpmov(u, t);
				break;
			}
		}
		if (j<n - 1) continue;
		mpmul(x, u, v);// Get square root from reciprocal and return.
			mplsh(x);
		mpmov(w, x);
		return;
	}
}



void MParith::mp2dfr(VecUchar_IO &a, string &s)
//Converts a radix 256 fraction a[0..n - 1](radix point before a[0]) to a decimal fraction represented
//as an ASCII string s[0..m - 1], where m is a returned value.The input array a[0..n - 1]
//is destroyed.NOTE: For simplicity, this routine implements a slow(/ N2) algorithm.Fast
//(/ N lnN), more complicated, radix conversion algorithms do exist.
{
	const Uint IAZ = 48;
	char buffer[4];
	Int j, m;
	Int n = a.size();
	m = Int(2.408*n);
	sprintf(buffer, "%d", a[0]);
	s = buffer;
	s += '.';
	mplsh(a);
	for (j = 0; j<m; j++) {
		mpsmu(a, a, 10);
		s += a[0] + IAZ;
		mplsh(a);
	}
}


string MParith::mppi(const Int np) {
//	Demonstrate multiple precision routines by calculating and printing the first np bytes of 	.
	const Uint IAOFF = 48, MACC = 2;
	Int ir, j, n = np + MACC;
	Uchar mm;
	string s;
	VecUchar x(n), y(n), sx(n), sxi(n), z(n), t(n), pi(n), ss(2 * n), tt(2 * n);
	t[0] = 2;// Set T D 2.
	for (j = 1; j<n; j++) t[j] = 0;
	mpsqrt(x, x, t); //Set X0 D
		
		mpadd(pi, t, x);// Set 	0 D 2C
		
		mplsh(pi);
	mpsqrt(sx, sxi, x);// Set Y0 D 21 = 4.
		mpmov(y, sx);
	for (;;) {
		mpadd(z, sx, sxi); //Set XiC1 D.X1 = 2
			//i CX1 = 2
			//i /= 2.
			mplsh(z);
		mpsdv(x, z, 2, ir);
		mpsqrt(sx, sxi, x); //Form the temporary T D YiX1 = 2
			//iC1 CX1 = 2
			//iC1 .
			mpmul(tt, y, sx);
		mplsh(tt);
		mpadd(tt, tt, sxi);
		mplsh(tt);
		x[0]++; //Increment XiC1 and Yi by 1.
			y[0]++;
		mpinv(ss, y); //Set YiC1 D T = .Yi C1 / .
			mpmul(y, tt, ss);
		mplsh(y);
		mpmul(tt, x, ss); //Form temporary T D.XiC1 C1 /= .Yi C1 / .
			mplsh(tt);
		mpmul(ss, pi, tt);// Set 	iC1 D T	i .
			mplsh(ss);
		mpmov(pi, ss);
		mm = tt[0] - 1; //If T D 1, then we have converged.
		for (j = 1; j < n - 1; j++)
		if (tt[j] != mm) break;
		if (j == n - 1) {
			mp2dfr(pi, s);
		//	Convert to decimal for printing.NOTE: The conversion routine, for this demonstration
		//		only, is a slow(/ N2) algorithm.Fast(/ N lnN), more complicated,
		//		radix conversion algorithms do exist.
				s.erase(Int(2.408*np), s.length());
			return s;
		}
	}
}
