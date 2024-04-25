import cv2
import numpy as np

# Load an image from file
image = cv2.imread("example.jpg")

# Check if the image was loaded successfully
if image is None:
    print("Error: Unable to load image.")
    exit(1)

# Resize the image to make it smaller
resized_image = cv2.resize(image, None, fx=0.2, fy=0.2)

# Convert the resized image to HSV color space
hsv_image = cv2.cvtColor(resized_image, cv2.COLOR_BGR2HSV)

# Define lower and upper bounds for blue color in HSV
lower_blue = np.array([100, 50, 50])
upper_blue = np.array([130, 255, 255])

# Create a mask for blue color
blue_mask = cv2.inRange(hsv_image, lower_blue, upper_blue)

# Define lower and upper bounds for green color in HSV
lower_green = np.array([40, 50, 50])
upper_green = np.array([80, 255, 255])

# Create a mask for green color
green_mask = cv2.inRange(hsv_image, lower_green, upper_green)

# Define lower and upper bounds for red color in HSV
lower_red1 = np.array([0, 50, 50])
upper_red1 = np.array([10, 255, 255])
lower_red2 = np.array([160, 50, 50])
upper_red2 = np.array([180, 255, 255])

# Create masks for red color (combining hue ranges)
red_mask1 = cv2.inRange(hsv_image, lower_red1, upper_red1)
red_mask2 = cv2.inRange(hsv_image, lower_red2, upper_red2)
red_mask = cv2.bitwise_or(red_mask1, red_mask2)

# Convert the original image to grayscale
gray_image = cv2.cvtColor(resized_image, cv2.COLOR_BGR2GRAY)

# Convert the grayscale image to BGR color space
gray_bgr_image = cv2.cvtColor(gray_image, cv2.COLOR_GRAY2BGR)

# Create a copy of the original image for each color
blue_image = resized_image.copy()
green_image = resized_image.copy()
red_image = resized_image.copy()

# Apply the masks to the corresponding images
blue_image[np.where(blue_mask)] = [255, 0, 0]  # Blue color
green_image[np.where(green_mask)] = [0, 255, 0]  # Green color
red_image[np.where(red_mask)] = [0, 0, 255]  # Red color

# Combine the colored images with the grayscale image using the masks
result_image1 = cv2.bitwise_and(gray_bgr_image, blue_image, mask=blue_mask)
result_image2 = cv2.bitwise_and(gray_bgr_image, green_image, mask=green_mask)
result_image3 = cv2.bitwise_and(gray_bgr_image, red_image, mask=red_mask)

# Display the results
cv2.imshow("Result Blue", result_image1)
cv2.waitKey(0)
cv2.imshow("Result Green", result_image2)
cv2.waitKey(0)
cv2.imshow("Result Red", result_image3)
cv2.waitKey(0)
cv2.destroyAllWindows()
