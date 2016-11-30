Everything should run fine on Windows if ran from Visual Studio. all libraries and includes are in one folder called "lib" and "include". All models/images/materials are in the "res" folder.



1. Open up project solution in visual studio

2. Ensure that build target is x64

3. Run using CTRL + F5

NOTE: the result may take a very long time to display because it has to preload all the model frames beforehand.



Issues:
1.	Character material error - face texture does not render.
2.	Unable to solve per frame model animation efficiently. Skeletal animation would be easier but I could not solve it. 
3.	My solution to animation is inefficient as it takes a very long time to load all the model frames beforehand and animation is slow.