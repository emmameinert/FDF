# FDF

Fdf or "fil de fer" is my very first graphics project. 


<img width="722" alt="Screen Shot 2023-11-08 at 4 31 04 PM" src="https://github.com/emmameinert/Hiveprojects_fdf/assets/110816436/a1b4b8f6-8662-4e31-8028-5229c50d400c"> 

## Key learnings 

- looking into parsing with this one using my [Get_next_line](https://github.com/emmameinert/Hiveproject_gnl) 
  
- making a 2D map 3D looking with isometric projection.
  
- coming up with a line drawing algorithm using [linear interpolation](https://en.wikipedia.org/wiki/Linear_interpolation)
  
- learning to use a graphics library (mlx, given by the 42school in this case)
  
- getting deeper knowledge of the use of structs (e.g. using them as coordinates)

## Isometric projection

Isometric projection is used for giving 2D drawings depth and make them look like 3D.

This is done by using a Rotation matrix on each coordinate of the map with a specific angle (I chose 30 and 60 degrees for my optics).

<img width="218" alt="Screen Shot 2023-11-09 at 11 45 26 AM" src="https://github.com/emmameinert/Hiveprojects_fdf/assets/110816436/677705b1-a136-4421-a855-a97c552b61df">

[Source](https://en.wikipedia.org/wiki/Rotation_matrix) 

## Linear interpolation

I use linear interpolation for drawing my lines, especially the diagonal lines are usually a problem. 
Linear interpolation is a calculation to find a a third point on the imaginary line between two existing ones. 

<img width="315" alt="Screen Shot 2023-11-09 at 11 51 33 AM" src="https://github.com/emmameinert/Hiveprojects_fdf/assets/110816436/c90cc91a-ae4b-4437-9fb2-05746e9191e4">

[(Source)](https://en.wikipedia.org/wiki/Linear_interpolation)

With the coordinates of the two points in a coordinate system one can calculate the slope and use that to find all coordinates with the same slope between the two original points. By setting the pixels for each of those found points, a diagonal line can be drawn.
