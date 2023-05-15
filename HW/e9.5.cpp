/* Implement a class Rectangle. Provide a constructor to construct a rectangle with a 
given width and height, member functions get_perimeter and get_area that compute 
the perimeter and area, and a member function void resize(double factor) that resizes 
the rectangle by multiplying the width and height by the given factor.*/

class Rectangle{
    private:
        double width;
        double height;
    public:
        Rectangle(double w, double h);
        double get_perimeter();
        double get_area();
        void resize(double factor);
};

Rectangle::Rectangle(double w, double h){
    width = w;
    height = h;
}

double Rectangle::get_area(){
    return (width*height);
}

double Rectangle::get_perimeter(){
    return (2*width + 2*height);
}

void Rectangle::resize(double factor){
    width *= factor;
    height *= factor;
}