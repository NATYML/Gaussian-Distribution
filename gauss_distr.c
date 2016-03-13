#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Usage: ./gauss_distr.out
		    L box
		    Media 
		    Standar deviation
		    Number of points
*/

/***************** Gaussian distribution function **********************/

double GAUSS_DIST( double *f, double r, double mu, double sigma ){

	*f = 1/(sigma*sqrt(2.*M_PI))*exp(-0.5*(r-mu)*(r-mu)/(sigma*sigma) );	

	return 0;
}

/******************************* Main ***********************************/

int main( int argc, char * argv[]   ){
	
	int i, N_points;
	double r0, Lbox, rmax, mu, sigma, fval, f_max, f, fborrar;
	double theta, phi;
	FILE *fp; 
	srand48(time(NULL)); 

	//File where positions will be stored
	fp = fopen("pos.dat","w");

	//Input variables
	Lbox = atof( argv[1] );
	mu = atof( argv[2] );
	sigma = atof( argv[3] ); 
	N_points = atoi( argv[4] );  
	
  	//Maximum value of function for Gaussian Distribution
  	//r = mu 
  	GAUSS_DIST( &f_max, mu, mu, sigma );
  	
  	i = 0;
    while ( i < N_points ){
 
    	//Uniform random number
	    r0 = drand48()*Lbox; 
		//Random number distributed between 0 and fmax
		fval = f_max*drand48();
		//Value of distribution function in r0
    	GAUSS_DIST( &f, r0, mu, sigma );

    	//Rejection method
    	if ( fval < f ){
    		
    		theta = acos( 1 - 2*drand48() );
    		phi = 2*M_PI*drand48();
    		r0 = r0+ 0.5*Lbox; 
    		fprintf( fp, "%lf %lf %lf %lf\n",r0*sin(theta)*cos(phi)
    						            	,r0*sin(theta)*sin(phi)
    						            	,r0*cos(theta)
    						            	,1. );
    		i++;
      	}	
    }

    fclose(fp);
  
return 0;	
}