/*
*   @author      : SRvSaha
*   Filename     : fluid_mechanics.c
*   Timestamp    : 23:52 04-October-2016 (Tuesday)
*   Description  : Code to Compute the Fluid Mechanics Stuffs
*   Requirements : C++ 11. For Linux : g++ 4.8.2(or higher)
*
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#define CIN(n) scanf("%f",&n);
using namespace std;

float modulus(float num)
{
    if(num > 0)
        return num;
    else return -num;
}

int main()
{
    float N; // For the Manning's Constant
    float b; // for the width
    int size;
    float g = 9.81; // value for 'g'
    float y[10000]; // for values of y
    float s; // for the bed-slope
    float Q; // for the discharge
    float q; // discharge per unit width
    float area;
    float perimeter;
    float hydraulic_radius;
    float velocity;
    float del_E; // for delta E
    float del_X; // for delta X
    float velocity_head; // this is the velocity head
    float total_energy; // total energy
    float sf; // for sf of each case
    float temp; // to store the temp value of sf
    float temp_e; // to store the temp energy
    float sf_mean_sf; // This is S(not) minus SF(bar) or (s-mean_sf)
    float mean_sf; // mean of bed-slope
    float sum = 0; // temp for calculating sum of dX
    float ans; // temp variable for polynomial constant calculation
    float Y; // this is Yn the root of the equation
    float y_critical; // Yc

    string A; // for Area expression
    string P; // for Perimeter expression
    string R; // for Hydraulic Radius
    string ss; // for temporary use

    printf("Enter the Manning's Constant : ");
    CIN(N)
    printf("Enter the width (b) : ");
    CIN(b)
    printf("Enter the bed-slope (s) : ");
    CIN(s)
    printf("Enter the discharge (Q) : ");
    CIN(Q)
    printf("How many values of depth do you want to enter : \n");
    scanf("%d",&size);
    printf("Enter %d values of depth : \n",size); // Enter space separated values
    for(int i = 0; i < size; i++){
        scanf("%f",&y[i]);
    }
    // The Part of the Equation
    cout<<"\n#################################################################################################################"<<std::endl;
    ss = to_string(b);
    A = "("+ss.substr(0,ss.length()-3)+")y";
    cout<<"\nArea : "<<A<<endl;
    P = ss.substr(0,ss.length()-3) + " + 2y";
    cout<<"Perimeter : "<<P<<endl;
    R = A + " / (" + P + ")";
    cout<<"Hydraulic Radius : "<<R<<endl<<endl;
    ans = pow(((Q*N)/sqrt(s)),3) * pow(b,5);
    cout<<"EQUATION : ("<<to_string(ans)+")y^5 "+"- (4)y^2 "+"- ("+to_string(4*b)+")y - "+to_string((float)pow(b,2))+" = 0"<<endl<<endl;

    // The part for comparision and labelling the slope
    cout<< "Please enter the value of y after solving the equation : ";
    cin>>Y;
    cout<<std::endl;
    q = Q/b;
    y_critical = pow((pow(q,2)/g),0.333333);
    if(Y > y_critical){
        cout<<"Mild Slope\t:\t";
        if(y[0] > Y && Y > y_critical)
            cout<<"M-1 Profile"<<endl;
        else if (Y > y[0] && y[0] > y_critical)
            cout<<"M-2 Profile"<<endl;
        else if (Y > y_critical && y_critical > y[0])
            cout<<"M-3 Profile"<<endl;
    }
    else if (Y < y_critical){
        cout<<"Steep Slope\t:\t";
        if(y[0] > y_critical && y_critical > Y)
            cout<<"S-1 Profile"<<endl;
        else if (y_critical > y[0] && y[0] > Y)
            cout<<"S-2 Profile"<<endl;
        else if (y_critical > Y && Y > y[0])
            cout<<"S-3 Profile"<<endl;
    }
    else if(Y == y_critical){
        cout<<"Critical Slope"<<std::endl;
    }
    cout<<"\n#################################################################################################################"<<std::endl;
    // The Part of the Table
    printf("\n================================================================================================================\n");
    printf("Depth     Area    Perimeter  H.Radius  Velocity  Vel Head   Energy   Mean(SF)  S-Mean(SF)  del_E     del_x\n");
    printf("================================================================================================================\n\n");
    for(int i = 0; i < size; i++){
        area = b*y[i];
        perimeter = b + 2*y[i];
        hydraulic_radius = area / perimeter;
        velocity = Q/area;
        velocity_head = pow(velocity,2)/(2*g);
        total_energy = y[i] + velocity_head;
        sf = (pow(N,2) * pow(velocity,2)) / pow(hydraulic_radius,1.333333);
        if(i>0){ // i>0 is used cause for the first case there'll be no sf mean and del E
            mean_sf = (sf + temp) / 2;
            sf_mean_sf = s - mean_sf;
            //sf_mean_sf = modulus(sf_mean_sf); //This is the absolute(modulus) function to convert -ve to +ve
            del_E = total_energy - temp_e;
            del_X = del_E / sf_mean_sf;
            //del_X = modulus(del_X); //This is the absolute(modulus) function to convert -ve to +ve
            if(del_X < 0)
                sum -= del_X;
            else
                sum += del_X;
        }
        temp_e = total_energy;
        temp = sf;
        if(i == 0)
        printf("%.3f  %f  %f  %f  %f  %f  %f\n",y[i],area,perimeter,hydraulic_radius,velocity,velocity_head,total_energy);
        else
            printf("%.3f  %f  %f  %f  %f  %f  %f  %f  %f  %f  %f\n",y[i],area,perimeter,hydraulic_radius,velocity,velocity_head,total_energy,mean_sf,sf_mean_sf,del_E,del_X);
    }
    printf("\n================================================================================================================\n\n");
    printf("\t\t\t\t  ******************************************");
    printf("\n\t\t\t\t     Submission of del_X is : %f\n",sum);
    printf("\t\t\t\t  ******************************************\n");
    return 0;
}
