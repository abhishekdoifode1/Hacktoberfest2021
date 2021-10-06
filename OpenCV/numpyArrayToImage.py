
# Python program to convert
# numpy array to image
  
# import required libraries
import numpy as np
from PIL import Image as im
  
# define a main function
def main():
  
    # create a numpy array from scratch
    # using arange function.
    # 1024x720 = 737280 is the amount 
    # of pixels.
    # np.uint8 is a data type containing
    # numbers ranging from 0 to 255 
    # and no non-negative integers
    array = np.arange(0, 737280, 1, np.uint8)
      
    # check type of array
    print(type(array))
      
    # our array will be of width 
    # 737280 pixels That means it 
    # will be a long dark line
    print(array.shape)
      
    # Reshape the array into a 
    # familiar resoluition
    array = np.reshape(array, (1024, 720))
      
    # show the shape of the array
    print(array.shape)
  
    # show the array
    print(array)
      
    # creating image object of
    # above array
    data = im.fromarray(array)
      
    # saving the final output 
    # as a PNG file
    data.save('gfg_dummy_pic.png')
  
# driver code
if __name__ == "__main__":
    
  # function call
  main()
