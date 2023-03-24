#include <iostream>
#include <string>
using namespace std;

struct Pixel
{
    int red;
    int green;
    int blue;
};

class Image
{
private:
    int row;
    int col;
    int depth;
    Pixel ***image;

public:
    Image(int d, int r, int c)
    {
        depth = d;
        row = r;
        col = c;
        image = new Pixel **[row];
        for (int i = 0; i < depth; i++)
        {
            image[i] = new Pixel *[col];
            for (int j = 0; j < row; j++)
            {
                image[i][j] = new Pixel[depth];
                for (int k = 0; k < col; k++)
                {
                    image[i][j][k].red = 0;
                    image[i][j][k].green = 0;
                    image[i][j][k].blue = 0;
                }
            }
        }
    }
    Image(const Image &img)
    {
        depth = img.depth;
        row = img.row;
        col = img.col;
        image = new Pixel **[row];
        for (int i = 0; i < depth; i++)
        {
            image[i] = new Pixel *[col];
            for (int j = 0; j < row; j++)
            {
                image[i][j] = new Pixel[depth];
                for (int k = 0; k < col; k++)
                {
                    image[i][j][k].green = img.image[i][j][k].green;
                    image[i][j][k].blue = img.image[i][j][k].blue;
                    image[i][j][k].red = img.image[i][j][k].red;
                }
            }
        }
    }

    ~Image()
    {
        delete[] image;
    }
    int getRow()
    {
        return row;
    }

    int getCol()
    {
        return col;
    }

    int getDepth()
    {
        return depth;
    }

    Pixel getPixel(int x, int y, int z)
    {
        return image[z][x][y];
    }
    void setPixel(int x, int y, int z, Pixel p)
    {
        image[x][y][z] = p;
    }
    void fill(Pixel p)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    image[i][j][k] = p;
                }
            }
        }
    }

    void clear()
    {
        Pixel pix;
        pix.blue = 0;
        pix.red = 0;
        pix.green = 0;
        fill(pix);
    }

    double getAverageBrightness()
    {
        double totalBrightness = 0.0;
        int totalPixels = getRow() * getCol() * getDepth();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    totalBrightness = totalBrightness + image[i][j][k].green + image[i][j][k].blue + image[i][j][k].red;
                }
            }
        }
        double AverageBrightness = totalBrightness / totalPixels;
        return AverageBrightness;
    }
    int getMaximumBrightness(int depth)
    {
        int MaximumBrightness = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (MaximumBrightness < image[i][j][depth].green)
                {
                    MaximumBrightness = image[i][j][depth].green;
                }
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (MaximumBrightness < image[i][j][depth].blue)
                {
                    MaximumBrightness = image[i][j][depth].blue;
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (MaximumBrightness < image[i][j][depth].red)
                {
                    MaximumBrightness = image[i][j][depth].red;
                }
            }
        }
        return MaximumBrightness;
    }
    int countBrightPixel()
    {
        int counter = 0;
        for (int i = 0; i < getRow(); i++)
        {
            for (int j = 0; j < getCol(); j++)
            {
                for (int k = 0; k < getDepth(); k++)
                {
                    if (image[i][j][k].red == 255 || image[i][j][k].green == 255 || image[i][j][k].blue == 255)
                    {
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
    void transposePixel(int depth);
};
