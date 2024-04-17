add_executable(
    image_processor
    image_processor.cpp
        image_processor.h InputOutput.cpp InputOutput.h image.cpp image.h CommandInterpretator.cpp CommandInterpretator.h Filter.h Negative.cpp Negative.h Grayscale.cpp Grayscale.h Sharpening.cpp Sharpening.h EdgeDetection.cpp EdgeDetection.h Crop.cpp Crop.h)
