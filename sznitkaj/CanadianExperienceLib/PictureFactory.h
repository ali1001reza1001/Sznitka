/**
 * @file PictureFactory.h
 * @author julia
 *
 *
 */
 
#ifndef PICTUREFACTORY_H
#define PICTUREFACTORY_H


class Picture;

/**
 * A factory class that builds our picture.
 */
class PictureFactory {
private:

public:
 std::shared_ptr<Picture> Create(std::wstring imagesDir);
};



#endif //PICTUREFACTORY_H
