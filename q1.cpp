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
        image = new Pixel **[depth];
        for (int k = 0; k < depth; k++)
        {
            image[k] = new Pixel *[row];
            for (int i = 0; i < row; i++)
            {
                image[k][i] = new Pixel[col];
                for (int j = 0; j < col; j++)
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
        image = new Pixel **[depth];
        for (int k = 0; k < depth; k++)
        {
            image[k] = new Pixel *[row];
            for (int i = 0; i < row; i++)
            {
                image[k][i] = new Pixel[col];
                for (int j = 0; j < col; j++)
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
        for (int i = 0; i < depth; i++)
        {
            for (int j = 0; j < row; j++)
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
        for (int k = 0; k < depth; k++)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    image[k][i][j] = p;
                }
            }
        }
    }

    void clear()
    {
        fill({0, 0, 0}); // fill with black
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
        double totalBrightness = 0.0;

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
        return totalBrightness;
    }
    int countBrightPixel();
    void transposePixel(int depth);
};
