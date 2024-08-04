import cv2
# Load the pre-trained Haar Cascade classifier for face detection
face_cascade = cv2.CascadeClassifier('./haarcascade_frontalface_default.xml')
# Read the image
image_path = "ucl-2.png" # Replace "ucl.png" with the path to your image
image = cv2.imread(image_path)
if image is None:
 print("Failed to load the image.")
else:
 # Convert the image to grayscale
 gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
 # Detect faces in the image
 faces = face_cascade.detectMultiScale(gray_image, scaleFactor=1.1, minNeighbors=5, minSize=(30, 
30))
 # Draw rectangles around the detected faces
 for (x, y, w, h) in faces:
 cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)
 # Display the image with detected faces
 cv2.imshow("Image with Detected Faces", image)
 cv2.waitKey(0)
 cv2.destroyAllWindows()