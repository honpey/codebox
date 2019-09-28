from resume_template import iPos
def update_project_info(resume):
    proj_start = resume[iPos['PROJECT_START_TIME']].strip()
    proj_end = resume[iPos['PROJECT_END_TIME']].strip()
    proj_name = resume[iPos['PROJECT_NAME']].strip()
    proj_brief = resume[iPos['PROJECT_BRIEF']].strip()
    proj_scale = resume[iPos['PROJECT_SCALE']].strip()
    proj_role = resume[iPos['PROJECT_ROLE']].strip()
    proj_company = resume[iPos['PROJECT_COMPANY']].strip()
    proj_zhize = resume[iPos['PROJECT_ZHIZE']].strip()
    proj_summary = resume[iPos['PROJECT_SUMMARY']].strip()

