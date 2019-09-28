from resume_template import iPos
def update_language_info(resume):
    lang_name = resume[iPos['LANGUAGE_NAME']].strip()
    lang_certification = resume[iPos['LANGUAGE_CERTIFICATION']].strip()
    lang_description = resume[iPos['LANGUAGE_DESCRIPTION']].strip()

def update_certification_info(resume):
    cert_name = resume[iPos['CERTIFICATION_NAME']].strip()
    cert_time = resume[iPos['CERTIFICATION_TIME']].strip()
    cert_institution = resume[iPos['CERTIFICATION_INSTITUTION']].strip()
    cert_description = resume[iPos['CERTIFICATION_DESCRIPTION']].strip()

