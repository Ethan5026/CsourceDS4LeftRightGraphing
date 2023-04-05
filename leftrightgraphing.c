
#include <stdio.h>


int scale_gyro_for_screen(double gyro_value, char one, char two);

int scale_joy_for_screen(double joy_value, char one, char two);

void print_chars(int number, char char_to_print);

void graph_line(int number, int current_mode);


// Run with ./ds4rd.exe -d 054c:05c4 -D DS4_BT -g -b -j | ./leftrightgraphing

int main(int argc, char *argv[])
{
    double gx, gy, gz;               

    int triangle, circle, x_button, square,        

            left_joy_x_axis, left_joy_y_axis,      
            right_joy_x_axis, right_joy_y_axis,

            scaled_gyro_pitch, scaled_gyro_roll,  

            scaled_joy_pitch, scaled_joy_roll;     

 
	int doGyro=1;
	int doRoll=1;
	printf("========================================================\n");
	printf("Welcome to the L/R graphing program!\nTo change between roll and pitch, press the X button.\n To change between gyro and joystick press the O button.\nPress Triangle to start and stop the program\n");
	printf("========================================================\n");
	while(triangle==0){
		scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d",  &gx, &gy,&gz, &triangle, &circle, &x_button, &square, 
		&left_joy_x_axis, &left_joy_y_axis, &right_joy_x_axis, &right_joy_y_axis);
	}
	while(triangle!=0){
		scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d",  &gx, &gy,&gz, &triangle, &circle, &x_button, &square, 
		&left_joy_x_axis, &left_joy_y_axis, &right_joy_x_axis, &right_joy_y_axis); 
	}

    do
    {
        scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d",  &gx, &gy,&gz, &triangle, &circle, &x_button, &square, 
		&left_joy_x_axis, &left_joy_y_axis, &right_joy_x_axis, &right_joy_y_axis);
		
		if(x_button==1){
			if(doRoll==0){
				doRoll=1;
				
			}
			else if(doRoll==1){
				doRoll=0;
			}
			while(x_button!=0){
			scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d",  &gx, &gy,&gz, &triangle, &circle, &x_button, &square, 
			&left_joy_x_axis, &left_joy_y_axis, &right_joy_x_axis, &right_joy_y_axis);
			}
		}
		else if(circle==1){
			if(doGyro==0){
				doGyro=1;
			}
			else if(doGyro==1){
				doGyro=0;
			}
			while(circle!=0){
			scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d, %d, %d",  &gx, &gy,&gz, &triangle, &circle, &x_button, &square, 
			&left_joy_x_axis, &left_joy_y_axis, &right_joy_x_axis, &right_joy_y_axis);
			}
		}
       
		if((doRoll==1)&&(doGyro==1)){
			scale_gyro_for_screen(gx, 'R', 'L');
		}
		else if((doRoll==1)&&(doGyro==0)){
			scale_joy_for_screen(right_joy_x_axis, 'R', 'L');
		}
		else if((doRoll==0)&&(doGyro==1)){
			scale_gyro_for_screen(gz, 'F', 'B');
		}
		else if((doRoll==0)&&(doGyro==0)){
			scale_joy_for_screen(right_joy_y_axis, 'F', 'B');
		}

       


        fflush(stdout);

    } while (triangle!=1); 

    return 0;

}


int scale_gyro_for_screen(double gyro_value, char one, char two)
{ 
	int i;
	i = gyro_value * 40;
	if(gyro_value<0){
		print_chars(i,one); //R
	}
	else if(gyro_value>0){
		print_chars(i, two); //L
	}
	}

int scale_joy_for_screen(double joy_value, char one, char two)
{
int i= joy_value /128.0 *40.0;
	if(joy_value<0){
		print_chars(-i,two);
	}
	else if(joy_value>0){
		print_chars(-i, one);
}
}



void print_chars(int number, char char_to_print){
	 int i;
	 printf("\n");
	if (number>0){
		int space = 40 - number;
		for(i=0; i<space;++i){
			printf(" ");
		}
		for(i=0; i<number; ++i){
			printf("%c", char_to_print);
		}
	}
	else if (number==0){
		printf("                                        0");
	}
	else if(number<0){
		printf("                                         ");
		for(i=0; i<-number; ++i){
			printf("%c", char_to_print);
		}
	
	}
}
