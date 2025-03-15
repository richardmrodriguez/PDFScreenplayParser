#pragma once

#include <string>
#include <vector>

enum SPType {
    SP_ACTION = 0,

    SP_CHARACTER,
    SP_CHARACTER_EXTENSION,
    SP_PARENTHETICAL,
    SP_DIALOGUE,
    SP_DG_MORE_CONTINUED,
    //DUAL DIALOGUE
    SP_DD_L_CHARACTER,
    SP_DD_L_PARENTHETICAL,
    SP_DD_L_DIALOGUE,
    SP_DD_L_MORE_CONTINUED,
    SP_DD_R_CHARACTER,
    SP_DD_R_PARENTHETICAL,
    SP_DD_R_DIALOGUE,
    SP_DD_R_MORE_CONTINUED,
    // SCENE HEADING
    SP_SCENE_HEADING,
    SP_INT_EXT,
    SP_TIME_OF_DAY,
    SP_LOCATION,
    SP_SUBLOCATION,
    SP_SCENENUM, // Nominal scene number
    SP_REVISION_MARGIN_MARKER, // asterisks in the left and/or right margins indicate a line or lines have been revised
    
    SP_TRANSITION,
    SP_MORE_CONTINUED,
    SP_PAGENUM, // Nominal page number
    SP_PAGE_REVISION_HEADER, //may or may not include the date / color (I think it's two lines usually, but it could be one line potentially...?)
    SP_FOOTER, // Not sure what footers are used for but....
    // TITLE PAGE
    TP_TITLE,
    TP_BYLINE,
    TP_AUTHOR,
    TP_DRAFT_DATE,
    TP_CONTACT,
    // -------------
    SP_OTHER,
    SP_BLANK, // BLANK element?
    SP_OMITTED,
    // Non- content text (asterisks and/or scene numbers in the margins, headers and footers, page numbers, etc.)
    NON_CONTENT_TOP,
    NON_CONTENT_BOTTOM,
    NON_CONTENT_LEFT,
    NON_CONTENT_RIGHT,
    
    _TYPECOUNT
}


//TODO: MISSING TYPES
std::string SPTypeToString(SPType type) {
    switch (type) {
        case SP_ACTION:             return "SP_ACTION";
        case SP_CHARACTER:          return "SP_CHARACTER";
        case SP_CHARACTER_EXTENSION:return "SP_CHARACTER_EXTENSION";
        case SP_PARENTHETICAL:      return "SP_PARENTHETICAL";
        case SP_DIALOGUE:           return "SP_DIALOGUE";
        case SP_DG_MORE_CONTINUED   return "SP_DG_MORE_CONTINUED";
        //DUAL DIALOGUE
        case SP_DD_L_CHARACTER:     return "SP_DD_L_CHARACTER";
        case SP_DD_L_PARENTHETICAL: return "SP_DD_L_PARENTHETICAL";
        case SP_DD_L_DIALOGUE:      return "SP_DD_L_DIALOGUE";
        case SP_DD_L_MORE_CONTINUED return "SP_DD_L_MORE_CONTINUED";
        case SP_DD_R_CHARACTER:     return "SP_DD_R_CHARACTER";
        case SP_DD_R_PARENTHETICAL: return "SP_DD_R_PARENTHETICAL";
        case SP_DD_R_DIALOGUE:      return "SP_DD_R_DIALOGUE";
        case SP_DD_R_MORE_CONTINUED return "SP_DD_R_MORE_CONTINUED";
        // SCENE HEADING
        case SP_SCENE_HEADING:      return "SP_SCENE_HEADING";
        case SP_INT_EXT:            return "SP_SUBLOCATION";
        case SP_TIME_OF_DAY:        return "SP_LOCATION";
        case SP_LOCATION:           return "SP_TIME_OF_DAY";
        case SP_SUBLOCATION:        return "SP_INT_EXT";
        
        case SP_TRANSITION:         return "SP_TRANSITION";
        case SP_MORE_CONTINUED      return "SP_MORE_CONTINUED"
        // TITLE PAGE
        case TP_TITLE:              return "TP_TITLE";
        case TP_BYLINE:             return "TP_BYLINE";
        case TP_AUTHOR:             return "TP_AUTHOR";
        case TP_DRAFT_DATE:         return "TP_DRAFT_DATE";
        case TP_CONTACT:            return "TP_CONTACT";
        //-------------
        case NON_CONTENT_TOP:       return "NON_CONTENT_TOP";
        case NON_CONTENT_BOTTOM:    return "NON_CONTENT_BOTTOM";
        case NON_CONTENT_LEFT:      return "NON_CONTENT_LEFT";
        case NON_CONTENT_RIGHT:     return "NON_CONTENT_RIGHT";
        case SP_OTHER:              return "SP_OTHER";
        default:                    return "UNKNOWN";
    }
}

std::array<const char*, _TYPECOUNT> getSPTypesAsStrings() {
    std::array<const char*, _TYPECOUNT> alltypes;

    for (int = SP_ACTION, i<_TYPECOUNT, i++) {
        SPType t = static_cast<SPType>(i);
        alltypes[i] = SPTypeToString(t);
    }

    return alltypes;
}



typedef struct ScreenplayDoc 
{
    vector<ScreenplayPage> pages;
};

enum ScreenplayPageFormat {
    PS_US,
    PS_A4
}

struct ScreenplayPage 
{
    vector<ScreeplayLine> lines;
    std::string pagenum;
    bool revised = false;
    std::string revision_color;
    ScreenplayPageFormat page_format = PS_US;
        
};

struct ScreenplayLine 
{
    vector<ScreenplayTextElement> text_elements;
    std::string scenenum;
    bool revised = false;
    bool blank = true;
};

struct ScreenplayTextElement {
    std::string text;
    SPType element_type = SPType::SP_BLANK;
}
