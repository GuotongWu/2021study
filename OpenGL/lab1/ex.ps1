gcc $($args[0]).c -o bin/$($args[0]).exe -lglut32 -lopengl32 -lglu32
./bin/$($args[0]).exe