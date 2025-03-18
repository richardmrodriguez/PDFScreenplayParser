

#include "screenplay_doc.hpp"

//TODO: MISSING TYPES
std::string SPTypeToString(SPType type)
{
    switch (type) {
        case SP_ACTION:                 return std::string("SP_ACTION");
        case SP_CHARACTER:              return std::string("SP_CHARACTER");
        case SP_CHARACTER_EXTENSION:    return std::string("SP_CHARACTER_EXTENSION");
        case SP_PARENTHETICAL:          return std::string("SP_PARENTHETICAL");
        case SP_DIALOGUE:               return std::string("SP_DIALOGUE");
        case SP_DG_MORE_CONTINUED:      return std::string("SP_DG_MORE_CONTINUED");
        //DUAL DIALOGUE
        case SP_DD_L_CHARACTER:         return std::string("SP_DD_L_CHARACTER");
        case SP_DD_L_PARENTHETICAL:     return std::string("SP_DD_L_PARENTHETICAL");
        case SP_DD_L_DIALOGUE:          return std::string("SP_DD_L_DIALOGUE");
        case SP_DD_L_MORE_CONTINUED:    return std::string("SP_DD_L_MORE_CONTINUED");
        case SP_DD_R_CHARACTER:         return std::string("SP_DD_R_CHARACTER");
        case SP_DD_R_PARENTHETICAL:     return std::string("SP_DD_R_PARENTHETICAL");
        case SP_DD_R_DIALOGUE:          return std::string("SP_DD_R_DIALOGUE");
        case SP_DD_R_MORE_CONTINUED:    return std::string("SP_DD_R_MORE_CONTINUED");
        // SCENE HEADING
        case SP_SCENE_HEADING:          return std::string("SP_SCENE_HEADING");
        case SP_INT_EXT:                return std::string("SP_INT_EXT");
        case SP_LOCATION:               return std::string("SP_LOCATION");
        case SP_SUBLOCATION:            return std::string("SP_SUBLOCATION");
        case SP_TIME_OF_DAY:            return std::string("SP_TIME_OF_DAY");
        case SP_SCENENUM:               return std::string("SP_SCENENUM");
        case SP_REVISION_MARGIN_MARKER: return std::string("SP_REVISION_MARGIN_MARKER");

        case SP_TRANSITION:             return std::string("SP_TRANSITION");
        case SP_MORE_CONTINUED:         return std::string("SP_MORE_CONTINUED");
        case SP_PAGENUM:                return std::string("SP_PAGENUM"); // Nominal page number
        case SP_PAGE_REVISION_HEADER:   return std::string("SP_PAGE_REVISION_HEADER"); //may or may not include the date / color (I think it's two lines usually, but it could be one line potentially...?)
        case SP_FOOTER:                 return std::string("SP_FOOTER");


        // TITLE PAGE
        case TP_TITLE:                  return std::string("TP_TITLE");
        case TP_BYLINE:                 return std::string("TP_BYLINE");
        case TP_AUTHOR:                 return std::string("TP_AUTHOR");
        case TP_DRAFT_DATE:             return std::string("TP_DRAFT_DATE");
        case TP_CONTACT:                return std::string("TP_CONTACT");
        //-------------
        case SP_BLANK:                  return std::string("SP_BLANK"); // BLANK element?
        case SP_OMITTED:                return std::string("SP_OMITTED");

        case SP_OTHER:                  return std::string("SP_OTHER");
        case NON_CONTENT_TOP:           return std::string("NON_CONTENT_TOP");
        case NON_CONTENT_BOTTOM:        return std::string("NON_CONTENT_BOTTOM");
        case NON_CONTENT_LEFT:          return std::string("NON_CONTENT_LEFT");
        case NON_CONTENT_RIGHT:         return std::string("NON_CONTENT_RIGHT");


        default:                        return std::string("UNKNOWN");
    }
}



std::array<std::string, _TYPECOUNT> getSPTypesAsStrings() {
    std::array<std::string, _TYPECOUNT> alltypes;

    for (int i = SP_ACTION; i < _TYPECOUNT; i++) {
        SPType t = static_cast<SPType>(i);
        alltypes[i] = SPTypeToString(t);
    }

    return alltypes;
}

