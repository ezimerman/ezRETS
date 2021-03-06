/*
 * Copyright (C) 2005,2006 National Association of REALTORS(R)
 *
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished
 * to do so, provided that the above copyright notice(s) and this
 * permission notice appear in all copies of the Software and that
 * both the above copyright notice(s) and this permission notice
 * appear in supporting documentation.
 */

#ifndef EZRETS_DATA_SOURCE_VALIDATOR_H
#define EZRETS_DATA_SOURCE_VALIDATOR_H

#include <wx/wx.h>
#include "commonfwd.h"

namespace odbcrets {

class DataSourceValidator : public wxValidator
{
  public:
    enum Field
    {
        NAME,
        LOGIN_URL,
        USERNAME,
        PASSWORD,
        STANDARD_NAMES,
        CUSTOM_USER_AGENT,
        USE_HTTP_GET,
        USE_HTTP_LOGGING,
        HTTP_LOG_EVERYTHING,
        HTTP_LOG_FILE,
        USE_DEBUG_LOGGING,
        DEBUG_LOG_FILE,
        RETS_VERSION,
        USE_BULK_METADATA,
        IGNORE_METADATA_TYPE,
        DECODE_LOOKUP_VALUES,
        ENABLE_USER_AGENT_AUTH,
        USER_AGENT_PASSWORD,
        USER_AGENT_AUTH_TYPE,
        TREAT_DECIMAL_AS_STRING,
        ENCODING_TYPE,
        USE_PROXY,
        PROXY_URL,
        PROXY_PASSWORD,
        SUPPORTS_QUERYSTAR,
        NUM_FIELDS
    };
    
    DataSourceValidator(DataSourcePtr dataSource, Field field = NAME);

    DataSourceValidator(const DataSourceValidator & rhs);
    
    virtual wxObject * Clone() const;

    bool Copy(const DataSourceValidator & rhs);

    DataSourceValidator & SetField(Field field);

    bool TransferToWindow();

    bool TransferFromWindow();

    bool Validate(wxWindow * parent);

  private:
    bool True(wxWindow * window);

    bool NonEmpty(wxWindow * window);

    bool NameToWindow(wxWindow * window);

    bool NameFromWindow(wxWindow * window);

    bool NameIsValid(wxWindow * window);

    bool LoginUrlToWindow(wxWindow * window);

    bool LoginUrlFromWindow(wxWindow * window);

    bool UsernameToWindow(wxWindow * window);

    bool UsernameFromWindow(wxWindow * window);

    bool PasswordToWindow(wxWindow * window);

    bool PasswordFromWindow(wxWindow * window);

    bool StdNamesToWindow(wxWindow * window);

    bool StdNamesFromWindow(wxWindow * window);

    bool UserAgentToWindow(wxWindow * window);

    bool UserAgentFromWindow(wxWindow * window);

    bool UseHttpGetToWindow(wxWindow * window);

    bool UseHttpGetFromWindow(wxWindow * window);

    bool UseHttpLoggingToWindow(wxWindow * window);

    bool UseHttpLoggingFromWindow(wxWindow * window);

    bool HttpLogEverythingFromWindow(wxWindow * window);

    bool HttpLogEverythingToWindow(wxWindow * window);

    bool HttpLogFileToWindow(wxWindow * window);

    bool HttpLogFileFromWindow(wxWindow * window);

    bool UseDebugLoggingToWindow(wxWindow * window);

    bool UseDebugLoggingFromWindow(wxWindow * window);

    bool DebugLogFileToWindow(wxWindow * window);

    bool DebugLogFileFromWindow(wxWindow * window);

    bool RetsVersionToWindow(wxWindow * window);

    bool RetsVersionFromWindow(wxWindow * window);

    bool UseBulkMetadataToWindow(wxWindow * window);

    bool UseBulkMetadataFromWindow(wxWindow * window);

    bool IgnoreMetadataTypeToWindow(wxWindow * window);

    bool IgnoreMetadataTypeFromWindow(wxWindow * window);

    bool DecodeLookupValuesToWindow(wxWindow * window);

    bool DecodeLookupValuesFromWindow(wxWindow * window);

    bool UserAgentPasswordToWindow(wxWindow * window);

    bool UserAgentPasswordFromWindow(wxWindow * window);

    bool UserAgentAuthTypeToWindow(wxWindow * window);

    bool UserAgentAuthTypeFromWindow(wxWindow * window);

    bool EnableUserAgentAuthToWindow(wxWindow * window);

    bool EnableUserAgentAuthFromWindow(wxWindow * window);

    bool TreatDecimalAsStringToWindow(wxWindow * window);

    bool TreatDecimalAsStringFromWindow(wxWindow * window);

    bool EncodingToWindow(wxWindow * window);

    bool EncodingFromWindow(wxWindow * window);

    bool UseProxyToWindow(wxWindow * window);

    bool UseProxyFromWindow(wxWindow * window);

    bool ProxyUrlToWindow(wxWindow * window);

    bool ProxyUrlFromWindow(wxWindow * window);

    bool ProxyPasswordToWindow(wxWindow * window);

    bool ProxyPasswordFromWindow(wxWindow * window);

    bool SupportsQueryStarToWindow(wxWindow * window);

    bool SupportsQueryStarFromWindow(wxWindow * window);

    typedef bool (DataSourceValidator::*ValidatingMethod)
        (wxWindow * window);

    static ValidatingMethod methods[NUM_FIELDS][3];
    static const int TO_WINDOW = 0;
    static const int FROM_WINDOW = 1;
    static const int VALIDATE = 2;
    static const char * FIELD_NAMES[NUM_FIELDS];

    DataSourcePtr mDataSource;
    Field mField;
};

}

#endif

/* Local Variables: */
/* mode: c++ */
/* End: */
