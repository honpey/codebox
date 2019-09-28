from resume_template import iPos

def update_education_info(resume):
    edu_start = resume[iPos['EDUCATION_START_TIME']].strip()
    edu_end = resume[iPos['EDUCATION_END_TIME']].strip()
    edu_school = resume[iPos['EDUCATION_SCHOOL']].strip()
    edu_colleage = resume[iPos['EDUCATION_COLLEGE']].strip()
    edu_major = resume[iPos['EDUCATION_MAJOR']].strip()
    edu_type = resume[iPos['EDUCATION_TYPE']].strip()
    edu_reference = resume[iPos['EDUCATION_REFERENCE']].strip()
    edu_reference_phone = resume[iPos['EDUCATION_REFERENCE_PHONE']].strip()
    edu_provice = resume[iPos['EDUCATION_PROVICE']].strip()
    edu_city = resume[iPos['EDUCATION_CITY']].strip()
    edu_district = resume[iPos['EDUCATION_DISTRICT']].strip()
    edu_street = resume[iPos['EDUCATION_STREET']].strip()
