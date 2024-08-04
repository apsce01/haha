import cv2
# Read the image
image_path = "annavru-1.jpeg" # Replace "your_image.jpg" with the path to your image
image = cv2.imread(image_path)
if image is None:
 print("Failed to load the image.")
else:
 # Convert the image to grayscale
 gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
 # Apply adaptive thresholding
 _, thresh = cv2.threshold(gray_image, 0, 255, cv2.THRESH_BINARY_INV + cv2.THRESH_OTSU)
 # Find contours in the thresholded image
 contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
 # Draw contours on the original image
 contour_image = image.copy()
 cv2.drawContours(contour_image, contours, -1, (0, 255, 0), 2) # Draw all contours with green color 
and thickness 2
 # Display the original image with contours
 cv2.imshow("Image with Contours", contour_image)
 cv2.waitKey(0)
 cv2.destroyAllWindows()
