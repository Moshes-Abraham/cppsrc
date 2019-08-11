#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "/usr/local/MATLAB/R2016b/extern/include/engine.h"


const int BUFFER_SIZE = 1024;
char buffer[BUFFER_SIZE];

int main()
{
	Engine * ep;
	mxArray * x1 = NULL;
	mxArray * y1 = NULL;
	if ((ep = engOpen("")) == NULL) 
	{
		std :: cout << "Failed to open the engine!\n";
		return 0;
	}
	engOutputBuffer(ep, buffer, BUFFER_SIZE);
	std :: cout << "Init Success" << std :: endl;

	double x[5] = {1.0, 2.5, 3.7, 4.4, 5.1};
	double y[5] = {3.3, 4.7, 9.6, 15.6, 21.3};
	x1 = mxCreateDoubleMatrix(1, 5, mxREAL);
	y1 = mxCreateDoubleMatrix(1, 5, mxREAL);

	memcpy((void *)mxGetPr(x1), (void *)x, sizeof(x));
	memcpy((void *)mxGetPr(y1), (void *)y, sizeof(y));

	engPutVariable(ep, "x", x1);
	engPutVariable(ep, "y", y1);

	engEvalString(ep, "plot(x, y)");
	getchar();
	engClose(ep);
	return 0;
}

