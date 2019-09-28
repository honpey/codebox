from resume_template import iPos

def create_or_update_basic_info(resume):

    # step1: get basic info from resume
    name = resume[iPos['PHONE']].strip()
    resume_way = resume[iPos['RESUME_WAY']].strip()
    resume_way2 = resume[iPos['RESUME_WAY2']].strip()
    user = resume[iPos['NAME']].strip()
    phone = resume[iPos['PHONE']].strip()
    gender = resume[iPos['GENDER']].strip()
    qq = resume[iPos['QQ']].strip()
    email = resume[iPos['EMAIL']].strip()

    birth_year = resume[iPos['BIRTH_YEAR']].strip()
    birth_month = resume[iPos['BIRTH_MONTH']].strip()
    birth_day = resume[iPos['BIRTH_DAY']].strip()
    identity = resume[iPos['IDENTITY']].strip()
    
    degree = resume[iPos['DEGREE']].strip()
    major = resume[iPos['MAJOR']].strip()
    school = resume[iPos['SCHOOL']].strip()
    graduate_time = resume[iPos['GRADUCATE_TIME']].strip()
    live_stat = resume[iPos['LIVE_STATE']].strip()
    self_description = resume[iPos['SELF_DESCRIPTION']].strip()
    
    birth_province = resume[iPos['BIRTH_PLACE_PROVINCE']].strip()
    birth_city= resume[iPos['BIRTH_PLACE_CITY']].strip()
    birth_district = resume[iPos['BIRTH_PLACE_DISTRICT']].strip()
    birth_place = resume[iPos['BIRTH_PLACE_STREET']].strip()
    
    current_settle_province = resume[iPos['CURRENT_SETTLE_PROVINCE']].strip()
    current_settle_city = resume[iPos['CURRENT_SETTLE_CITY']].strip()
    current_settle_district = resume[iPos['CURRENT_SETTLE_DISTRICT']].strip()
    current_settle_street = resume[iPos['CURRENT_SETTLE_STREET']].strip()
    
    marriage = resume[iPos['MARRIAGE']].strip()

    # step2: create the basic info
    
