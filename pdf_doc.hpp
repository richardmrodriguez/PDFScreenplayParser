#pragma once

#include <string>
#include <vector>

#ifndef TEXTPOS_H
#define TEXTPOS_H
#include <"text_position.h">
#endif

struct PDFPageSize 
{
    float x = -1.0f;
    float y = -1.0f;
    float resolution_points = 72.0f;
}

typedef struct PDFDoc 
{
    vector<PDFPage> pages;
};

struct PDFPage 
{
    vector<PDFLine> lines;
    PDFPageSize;
};

struct PDFLine 
{
    vector<PDFWord> words;
};

struct PDFWord 
{
    std::string text;
    TextPosition position;
    std::string font_name;
    float font_size;
};