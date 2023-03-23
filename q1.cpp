#include <iostream>
#include <cstdlib>

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
                    image[i][j][k].red = img.image[i][j][k].red;
                    image[i][j][k].green = img.image[i][j][k].green;
                    image[i][j][k].blue = img.image[i][j][k].blue;
                }
            }
        }
    }

    ~Image()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                delete[] image[i][j];
            }
            delete[] image[i];
        }
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
        image[z][x][y] = p;
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
        int totalPixels = row * col * depth;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    totalBrightness += image[i][j][k].blue + image[i][j][k].green + image[i][j][k].red;
                }
            }
        }

        return totalBrightness / totalPixels;
    }
    int getMaximumBrightness(int depth)
    {
        int MaximumBrightness = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (MaximumBrightness < image[i][j][depth].red)
                {
                    MaximumBrightness = image[i][j][depth].red;
                }
                if (MaximumBrightness < image[i][j][depth].green)
                {
                    MaximumBrightness = image[i][j][depth].green;
                }
                if (MaximumBrightness < image[i][j][depth].blue)
                {
                    MaximumBrightness = image[i][j][depth].blue;
                }
            }
        }
        return MaximumBrightness;
    }
    int countBrightPixel()
    {
        int counter = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
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
