from django.core.mail import send_mail

send_mail(
        'hello world',
        'here is the message',
        'bigjson@126.com',
        ['bigjason@126.com'],
        fail_silently=False,
        )
