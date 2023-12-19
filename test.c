d_list->x = 0;
d_list->y = 0;

int i = 0;				// N = i;
double c_img = 1;		//img is NUBi
double c_real = -1;		// real is NUB
double z_real = 0;
double z_img = 0;
double temp; 			//temp replaces z_real so we dont fuck up z_img;

while (i < 100)
{
	temp = z_real * z_real - z_img * z_img + c _real;
	z_img = 2 * z_real * z_img + c_img;
	z_real = temp;
	if (sqrt(z_real * z_real + z_img * z_img) > 2)  //this is basicaly a² + b² = c²  but its better to wwrite with out
		return (i);
	i++;
}
return (i);